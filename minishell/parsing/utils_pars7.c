/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:30:30 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/22 06:23:10 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**tab_dup(char **tab)
{
	char	**newtab;
	int		i;

	i = -1;
	newtab = malloc((tablen(tab) + 1) * sizeof(void *));
	while (tab[++i])
		newtab[i] = ft_strdup(tab[i]);
	newtab[i] = NULL;
	return (newtab);
}

void	del_com(int i)
{
	freetab(g_env.commande[i].argv);
	g_env.commande[i].argv = NULL;
	free(g_env.commande[i].argv);
	g_env.commande[i].argv = NULL;
	free(g_env.commande[i].exec);
	g_env.commande[i].exec = NULL;
	if (g_env.commande[i + 1].exec)
	{
		while (g_env.commande[i + 1].exec)
		{
			g_env.commande[i].argv = tab_dup(g_env.commande[i + 1].argv);
			g_env.commande[i].exec = ft_strdup(g_env.commande[i + 1].exec);
			freetab(g_env.commande[i + 1].argv);
			g_env.commande[i + 1].argv = NULL;
			free(g_env.commande[i + 1].argv);
			g_env.commande[i + 1].argv = NULL;
			free(g_env.commande[i + 1].exec);
			g_env.commande[i + 1].exec = NULL;
		}
	}
}

void	del_el(int i, int j)
{
	free(g_env.commande[i].exec);
	g_env.commande[i].exec = ft_strdup(g_env.commande[i].argv[j + 1]);
	while (g_env.commande[i].argv[(j) + 1])
	{
		free(g_env.commande[i].argv[j]);
		g_env.commande[i].argv[j] = ft_strdup(g_env.commande[i].argv[j + 1]);
		j++;
	}
	free(g_env.commande[i].argv[j]);
	g_env.commande[i].argv[j] = NULL;
}

static char	*while_cw(char **arg, int *i, const char *charset, int *compt)
{
	while ((*i < (int)ft_strlen((const char *)*arg)
			&& (*arg)[*i] && is_sep(&(*arg)[*i]) == 0
			&& is_charset((*arg)[*i], charset) == 0)
		|| ((is_sep(&(*arg)[*i]) == 1 || is_charset((*arg)[*i], charset) == 1)
			&& bsvalid(*arg, *i) == 1))
	{
		if (((*arg)[*i] == 34 || (*arg)[*i] == 39) && bsvalid((*arg), *i) == 0)
		{
			*arg = gestquote(*arg, i, compt);
			return (*arg);
		}
		(*i)++;
	}
	(*i)--;
	return (*arg);
}

int	compt_word(char **arg, const char *charset)
{
	int	i;
	int	compt;
	int	flag;

	i = -1;
	compt = 0;
	while (++i < (int)ft_strlen((const char *)*arg) && (*arg)[i])
	{
		compt++;
		flag = 0;
		if (is_sep(&(*arg)[i]) == 1)
		{
			compt++;
			i++;
		}
		while ((*arg)[i] && (is_charset((*arg)[i], charset) == 1)
			&& bsvalid(*arg, i) == 0)
			i++;
		if (((*arg)[i] == 34 || (*arg)[i] == 39) && bsvalid((*arg), i) == 0)
			*arg = gestquote(*arg, &i, &compt);
		else
			while_cw(arg, &i, charset, &compt);
	}
	return (compt + 1);
}
