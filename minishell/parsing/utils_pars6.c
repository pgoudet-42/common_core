/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 10:58:06 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/16 10:20:35 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "util.h"

void	free_env(int i)
{
	free(g_env.commande[i].argv[0]);
	g_env.commande[i].argv[0] = NULL;
	free(g_env.commande[i].exec);
	g_env.commande[i].exec = NULL;
}

void	rmarg3(int i, int *j)
{
	if (*j == 0)
	{
		g_env.commande[i].exec = ft_strdup(g_env.commande[i].argv[*j]);
		(*j)--;
	}
}

char	**rmarg2(char **inter, t_compt2 *compt2, int i)
{
	if (compt2->flag == 0)
	{
		inter = malloc(sizeof(void *) * (tablen(g_env.commande[i].argv) + 1));
		if (!inter)
			return (NULL);
		compt2->flag = 1;
	}
	inter[++compt2->y] = ft_strdup(g_env.commande[i].argv[compt2->x]);
	inter[compt2->y + 1] = NULL;
	return (inter);
}

void	else_rmarg(int i, int j, int x)
{
	x = j;
	if (g_env.commande[i].argv[x + 1])
	{
		while (g_env.commande[i].argv[x + 1])
		{
			free(g_env.commande[i].argv[x]);
			g_env.commande[i].argv[x]
				= ft_strdup(g_env.commande[i].argv[x + 1]);
			x++;
		}
	}
	else
	{
		free(g_env.commande[i].argv[x]);
		g_env.commande[i].argv[x] = NULL;
	}
}

void	rmarg(int i, int *j)
{
	t_compt2	compt2;
	char		**inter;
	int			flag;

	compt2.x = -1;
	compt2.y = -1;
	compt2.flag = 0;
	inter = NULL;
	flag = 0;
	if (ft_strcmp(g_env.commande[i].exec, "export") == 0)
		g_env.commande[i].argv[*j] = arg_fromarg(g_env.commande[i].argv[*j]);
	else if (ft_strcmp(g_env.commande[i].argv[*j], g_env.commande[i].exec) == 0)
	{
		compt2.x = *j;
		if (g_env.commande[i].argv[compt2.x + 1])
			del_el(i, compt2.x);
		else
			del_com(i);
	}
	else
		else_rmarg(i, *j, compt2.x);
}
