/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 07:04:13 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/21 16:09:35 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft2/get_next_line.h"
#include <limits.h>
#include "../running/ms_builtins.h"
#include "ms_run.h"

int	ms_exec_1(char *ex, char **ar)
{
	if (!*ex)
	{
		g_env.errnum = builtin_exec(ar, g_env.envp);
		exit(-1);
	}
	else
	{
		g_env.errnum = execve(ex, ar, g_env.envp);
		exit(-1);
	}
}

int	ms_exec(char *ex, char **ar, int in, int out)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (in != 0)
			dup2(in, 0);
		if (out != 1)
			dup2(out, 1);
		ms_exec_1(ex, ar);
	}
	else
	{
		wait4(pid, &status, status, NULL);
		g_env.errnum = status / 256 ;
		if (g_env.errnum > 10)
			g_env.errnum = 0;
	}
	return (pid);
}

int	ms_input(char **envp)
{
	int		res;
	char	*com;
	char	**argv2;

	write(1, "##> ", 4);
	res = get_next_line(0, &com);
	if (res < 1 )
	{
		ft_putendl_fd("exit", 1);
		exit (0);
	}
	com = var_inval(com, envp);
	argv2 = ft_splitp(com, " 	\n");
	if (arg_to_struct(argv2) == 0)
	{
		write(1, "malloc failed\n", 14);
		return (-1);
	}
	trait_arg();
	last_chance();
	return (0);
}

int	ms_check_path(t_command *tc, char *thepath, char **envp)
{
	int	res;
	int	n;

	res = 0;
	n = is_builtin(tc->argv[0]);
	if (n == 1)
	{
		*thepath = 0;
	}
	else if (n == 2)
	{
		g_env.errnum = builtin_exec_0(tc->argv, envp);
		res = 1;
	}
	else
	{
		if (!execpath(envp, thepath, tc->argv[0]))
		{
			res = error_print_2(tc->argv[0], "command not found", 127);
			if (tc->fd_out)
				tc->next = NULL;
		}
	}
	return (res);
}

int	pipe_exec(t_command *tc, int *in, char *thepath, int *p)
{
	int		xi;
	int		xo;

	xi = 0;
	if (tc->pip_in)
		xi = *in;
	xo = 1;
	if (tc->pip_out)
		xo = p[1];
	tc->pid = ms_exec(thepath, tc->argv, xi, xo);
	if (tc->pip_in)
		close(*in);
	if (tc->pip_out)
		close(p[1]);
	*in = p[0];
	return (0);
}
