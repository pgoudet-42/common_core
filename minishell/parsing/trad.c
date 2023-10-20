/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 07:28:32 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/16 10:45:27 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "util.h"

char	**declar_var(char *arg, char **var)
{
	char	**newenvp;
	int		k;
	int		j;

	k = 0;
	j = -1;
	while (var[k])
		k++;
	newenvp = malloc(sizeof(void *) * (k + 2));
	if (!newenvp)
		return (NULL);
	while (var[++j])
	{
		newenvp[j] = ft_strdup(var[j]);
		free(var[j]);
	}
	newenvp[j] = ft_strdup(arg);
	if (g_env.var)
		free(g_env.var);
	newenvp[k + 1] = NULL;
	return (newenvp);
}

char	*rm_bs(char *arg, int i)
{
	char	*newarg;
	int		j;
	int		k;

	j = -1;
	k = -1;
	newarg = malloc(ft_strlen(arg));
	if (!newarg)
		return (NULL);
	while (arg[++j])
	{
		if (j != i)
		{
			k++;
			newarg[k] = arg[k];
		}
		else
			j++;
	}
	free(arg);
	return (newarg);
}

void	gest_declar(int i, int *j, int *k)
{
	if (ft_strcmp(g_env.commande[i].exec, g_env.commande[i].argv[*j]) == 0
		|| ft_strcmp(g_env.commande[i].exec, "export") == 0)
	{
		g_env.var = declar_var(g_env.commande[i].argv[*j], g_env.var);
		rmarg(i, j);
		*k = -1;
	}
}

void	while_ta(int *k, int *i, int *j)
{
	while (++(*j) < tablen(g_env.commande[*i].argv))
	{
		*k = -1;
		while (*j < tablen(g_env.commande[*i].argv)
			&& g_env.commande[*i].argv[0] && *j >= 0
			&& ++*k < (int)ft_strlen(g_env.commande[*i].argv[*j])
			&& g_env.commande[*i].argv[*j][*k])
		{
			if (g_env.commande[*i].argv[*j][*k] == '='
				&& is_inquote(*k, g_env.commande[*i].argv[*j]) != 1)
				gest_declar(*i, j, k);
		}
	}
}

void	trait_arg(void)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	while (g_env.commande[++i].exec)
	{
		while_ta(&k, &i, &j);
		j = -1;
	}
}
