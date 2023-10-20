/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 08:14:26 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/21 16:10:05 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "ms_builtins.h"

void	sigintHandler_q2(int sig_num)
{
	(void)sig_num;
	if (write(1, "Quit: 3\n", 8) < 0)
	{
		return ;
	}
	g_env.errnum2 = 131;
	signal(SIGQUIT, sigintHandler_q2);
}

void	sigintHandler_q(int sig_num)
{
	(void)sig_num;
	if (write(1, "\b\b  \b\b", 6) < 0)
		return ;
	signal(SIGQUIT, sigintHandler_q);
}

void	sigintHandler_c(int sig_num)
{
	(void)sig_num;
	if (write(1, "\b\b  \n##> ", 9) < 0)
		return ;
	signal(SIGINT, sigintHandler_c);
}

void	sigintHandler_c2(int sig_num)
{
	(void)sig_num;
	if (write(1, "\n", 1) < 0)
		return ;
	signal(SIGINT, sigintHandler_c2);
}

int	get_last_error(void)
{
	if (g_env.errnum2)
	{
		g_env.errnum = g_env.errnum2;
		g_env.errnum2 = 0;
	}
	return (g_env.errnum);
}
