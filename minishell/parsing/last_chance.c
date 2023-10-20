/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_chance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:22:28 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/21 16:38:41 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "util.h"

int	is_dolvalid(char *arg)
{
	int	i;

	i = -1;
	if (arg)
		while (arg[++i])
			if ((arg[i] == '$' && bsvalid(arg, i) == 0)
				&& (arg[i] == '$' && is_inquote(i, arg) == 0))
				return (1);
	return (0);
}

char	*changevar_inval2(char *arg, char **envp)
{
	char	*new_argv;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new_argv = NULL;
	if (is_dolvalid(arg) == 1)
	{
		while (arg[++j])
			if (arg[j] == '$')
				new_argv = var_toval(&arg[j + 1], envp);
	}
	if (!new_argv)
	{
		free(arg);
		return (NULL);
	}
	free(arg);
	return (new_argv);
}

void	last_chance_w1(int *i)
{
	if (is_dolvalid(g_env.commande[*i].exec) == 1)
		g_env.commande[*i].exec
			= changevar_inval2(g_env.commande[*i].exec, g_env.var);
	if (g_env.commande[*i].argv)
		g_env.commande[*i].argv
			= changevar_inval(g_env.commande[*i].argv, g_env.var);
	if (!(g_env.commande[*i].exec) && tablen(g_env.commande[*i].argv) > 0)
	{
		g_env.commande[*i].exec = ft_strdup(g_env.commande[*i].argv[0]);
		i--;
	}
	else if (!(g_env.commande[*i].exec))
	{
		del_com(*i);
		(*i)--;
	}
}

void	last_chance_w2(int *i)
{
	int	j;

	j = -1;
	while (g_env.commande[*i].argv[++j])
	{
		if (j >= 0 && j < tablen(g_env.commande[*i].argv))
		{
			g_env.commande[*i].argv[j]
				= rmbs2(g_env.commande[*i].argv[j]);
		}
	}
	if (g_env.commande[*i].exec)
		g_env.commande[*i].exec = rmbs2(g_env.commande[*i].exec);
}

void	last_chance(void)
{
	int	i;

	i = -1;
	while (g_env.commande[++i].exec)
		last_chance_w1(&i);
	i = -1;
	while (g_env.commande[++i].exec)
		last_chance_w2(&i);
}
