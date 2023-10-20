/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:09:44 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/21 15:35:59 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft2/get_next_line.h"
#include <limits.h>
#include "running/ms_builtins.h"
#include "running/ms_run.h"

int	main_loop(t_command *tc, char **envp)
{
	int			res;
	int			p[2];
	int			in;

	while (tc)
	{
		res = ms_check_path(tc, g_env.thepath, envp);
		if (res == 0)
		{
			if (tc->pip_out)
			{
				pipe(p);
				tc->pip[0] = p[0];
				tc->pip[1] = p[1];
			}
			if (!res)
			{
				pipe_exec(tc, &in, g_env.thepath, p);
			}
		}		
		tc = tc->next;
	}
	return (res);
}

int	main_loop_wait(t_command *tc)
{
	int	status;

	while (tc)
	{
		if (tc->pid != 0)
		{
			wait4(tc->pid, &status, status, NULL);
		}
		tc = tc->next;
	}
	return (status);
}

int	main(int argc, char *argv[], char **envp)
{
	t_command	*tc0;
	int			res;

	(void)argc;
	(void)argv;
	tc0 = NULL;
	g_env.envp = envp;
	g_env.var = malloc(sizeof(void *));
	g_env.var[0] = NULL;
	g_env.errnum2 = 0;
	signal(SIGQUIT, sigintHandler_q);
	while (1)
	{
		signal(SIGINT, sigintHandler_c);
		signal(SIGQUIT, sigintHandler_q);
		res = ms_input(envp);
		signal(SIGINT, sigintHandler_c2);
		signal(SIGQUIT, sigintHandler_q2);
		tc0 = cmds_init(tc0);
		res = main_loop(tc0, envp);
		res = main_loop_wait(tc0);
		free_pl_com();
	}
	return (0);
}
