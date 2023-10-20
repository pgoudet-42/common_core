/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:10:45 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/16 14:23:19 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <limits.h>
#include "ms_builtins.h"
#include "ms_run.h"

t_command	*trait_tabls_0(int i)
{
	t_command	*prv;
	t_command	*tc;

	i = 0;
	prv = NULL;
	if (g_env.commande[0].exec == NULL)
		return (NULL);
	while (g_env.commande[i].exec)
	{
		tc = &g_env.commande[i];
		tc->prev = prv;
		if (tc->prev != NULL)
			tc->prev->next = tc;
		tc->next = NULL;
		tc->pip_in = 0;
		tc->pip_out = 0;
		tc->fd_in = 0;
		tc->fd_out = 0;
		tc->pid = 0;
		tc->pip[0] = 0;
		tc->pip[1] = 0;
		prv = tc;
		i++;
	}
	return (&g_env.commande[0]);
}

int	trait_tabls_pipe(t_command *tc)
{
	if (tc->prev)
	{
		tc->prev->pip_out = 1;
		if (tc->next)
		{
			tc->next->pip_in = 1;
			tc->prev->next = tc->next;
			tc->next->prev = tc->prev;
			free_t_com(tc);
			return (0);
		}
	}
	return (-1);
}

int	trait_tabls_rd_in(t_command *tc)
{
	char	**tmp;

	if (tc->prev)
	{
		tc->fd_out = 1;
		free(tc->exec);
		tc->exec = tc->prev->exec;
		tmp = tc->argv;
		tc->argv = tc->prev->argv;
		tc->prev->argv = tmp;
		tc->prev->exec = ft_strdup("redirin");
		free(tc->prev->argv[0]);
		tc->prev->argv[0] = ft_strdup(tc->prev->exec);
		tc->prev->fd_in = 1;
		tc->prev->pip_out = 1;
		tc->pip_in = 1;
		return (0);
	}
	return (-1);
}

int	trait_tabls_rd_out(t_command *tc, int dbl)
{
	if (tc->prev)
	{
		free(tc->exec);
		tc->prev->fd_out = 1;
		tc->prev->pip_out = 1;
		tc->pip_in = 1;
		if (dbl)
			tc->exec = ft_strdup("redirout2");
		else
			tc->exec = ft_strdup("redirout1");
		free(tc->argv[0]);
		tc->argv[0] = ft_strdup(tc->exec);
		return (0);
	}
	return (-1);
}

t_command	*cmds_init(t_command *tc)
{
	t_command	*tc0;

	tc0 = trait_tabls_0(0);
	tc = tc0;
	if (tc == NULL)
		return (NULL);
	while (tc)
	{
		if (tc->exec[0] == '|')
		{
			if (trait_tabls_pipe(tc) < 0)
				return (NULL);
		}
		else if (tc->exec[0] == '<')
		{
			if (trait_tabls_rd_in(tc) < 0)
				return (NULL);
		}
		else if (tc->exec[0] == '>')
			if (trait_tabls_rd_out(tc, tc->exec[1] == '>') < 0)
				return (NULL);
		tc = tc->next;
	}
	check_multi_redir(tc0);
	return (tc0);
}
