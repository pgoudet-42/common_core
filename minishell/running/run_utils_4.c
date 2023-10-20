/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:03:01 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/17 08:17:06 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ms_builtins.h"

void	check_swap(t_command *tc1, t_command *tc2)
{
	char		**s;

	s = tc1->next->argv;
	tc1->next->argv = tc2->next->argv;
	tc2->next->argv = s;
}

void	check_multi_redir(t_command *tc0)
{
	t_command	*tc1;
	t_command	*tc2;
	int			flag;

	flag = 0;
	while (tc0)
	{
		if (tc0->fd_out == 1)
		{
			if (!flag)
				tc1 = tc0;
			else
				tc2 = tc0;
			flag ++;
		}
		else
		{
			if (flag > 1)
			{
				check_swap(tc1, tc2);
			}	
			flag = 0;
		}
		tc0 = tc0->next;
	}
}
