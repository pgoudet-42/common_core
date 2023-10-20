/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:00:23 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/17 08:04:19 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <limits.h>
#include "ms_builtins.h"
#include "ms_run.h"

void	free_t_com(t_command *tc)
{
	int	i;

	free(tc->exec);
	i = 0;
	while (tc->argv[i])
		free(tc->argv[i++]);
	free(tc->argv);
}

void	free_pl_com(void)
{
	t_command	*tc;
	int			i;

	i = 0;
	tc = &g_env.commande[0];
	if (tc->exec != NULL)
	{
		while (tc)
		{
			free_t_com(tc);
			tc = tc->next;
		}
	}
	free(&g_env.commande[0]);
}

void	tabl_aff2(void)
{
	t_command	*tc;
	int			i;

	tc = &g_env.commande[0];
	if (tc->exec == NULL)
		return ;
	while (tc)
	{
		printf("%14p %14p %14p %d %d %d %d %d %d %d %s <%s>",
			tc->prev, tc, tc->next,
			tc->pip_in, tc->pip_out, tc->fd_in, tc->fd_out,
			tc->pip[0], tc->pip[1], tc->pid, tc->exec, tc->argv[0]);
		i = 1;
		while (tc->argv[i])
			printf(" <%s>", tc->argv[i++]);
		printf("\n");
		tc = tc->next;
	}
}
