/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 08:47:30 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/18 16:32:02 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_command	*mal_struct(char **arg, int *j)
{
	int			i;
	int			compt;
	t_command	*commande;

	i = -1;
	compt = 0;
	while (arg[++i])
	{
		if (is_charset(arg[i][0], "<>;") == 1 || ft_strcmp(arg[i], ">>") == 0)
			compt++;
		else if (arg[i][0] == '|')
			compt += 2;
		else
			compt++;
	}
	commande = malloc(sizeof(t_command) * (compt + 2));
	if (!commande)
		return (NULL);
	*j = compt + 2;
	if (!commande)
		return (NULL);
	return (commande);
}

int	malloc_struct(int *j, int *size, char **arg)
{
	g_env.commande = mal_struct(arg, j);
	if (g_env.commande == NULL)
	{
		g_env.commande = malloc(sizeof(void *));
		g_env.commande[0].exec = malloc(sizeof(void *));
		g_env.commande[0].exec = NULL;
		return (0);
	}
	if (!g_env.commande)
		return (0);
	while (arg[*size])
		(*size)++;
	return (1);
}

int	bsvalid(char *arg, int i)
{
	int	compt;

	compt = 0;
	while (i > 0 && arg[--i] == 92)
		compt++;
	if (compt % 2 == 1)
		return (1);
	return (0);
}

int	gotonextquote(char *arg, int i)
{
	i = 1;
	if (arg[0] == 34)
	{
		while (arg[i] && arg[i] != 34)
			i++;
	}
	else if (arg[0] == 39)
	{
		while (arg[i] && arg[i] != 39)
			i++;
	}
	return (i);
}

void	freetab(char **tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
		{
			free(tab[i]);
		}
		free(tab);
	}
	tab = NULL;
}
