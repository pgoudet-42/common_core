/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:38:41 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/18 16:27:58 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "util.h"

void	if_pipe(char **arg, t_compt *compt)
{
	if (compt->j >= 0 && compt->k != -1)
		g_env.commande[compt->j].argv[++compt->k] = NULL;
	compt->k = -1;
	g_env.commande[++compt->j].exec = ft_strdup(arg[compt->i]);
	g_env.commande[compt->j].argv[++compt->k] = ft_strdup(arg[compt->i]);
	g_env.commande[compt->j].argv[++compt->k] = NULL;
	compt->k = -1;
}

void	arg_to_struct2(char **arg, t_compt *compt)
{
	if (arg[compt->i][0] == ';')
	{
		if (compt->j >= 0)
			g_env.commande[compt->j].argv[++compt->k] = NULL;
		compt->k = -1;
	}
	else
	{
		if (compt->j < 0 || compt->k == -1)
		{
			compt->j++;
			g_env.commande[compt->j].exec = ft_strdup(arg[compt->i]);
		}
		while (arg[compt->i] && is_charset(arg[compt->i][0], "<>|;") == 0
			&& ft_strcmp(arg[compt->i], ">>") != 0)
		{
			g_env.commande[compt->j].argv[++compt->k]
				= ft_strdup(arg[compt->i]);
			compt->i++;
		}
		compt->i--;
	}
}

void	gest_if(char **arg, t_compt *compt)
{
	if (arg[compt->i][0] == '|')
		if_pipe(arg, compt);
	else if (arg[compt->i][0] == '>'
		|| arg[compt->i][0] == '<' || ft_strcmp(arg[compt->i], ">>") == 0)
	{
		if (compt->j >= 0)
			g_env.commande[compt->j].argv[++compt->k] = NULL;
		compt->k = -1;
		g_env.commande[++compt->j].exec = ft_strdup(arg[compt->i]);
		g_env.commande[compt->j].argv[++compt->k] = ft_strdup(arg[compt->i]);
	}
	else if (compt->i > 0 && arg[compt->i - 1][0] == '|')
	{
		g_env.commande[++compt->j].exec = ft_strdup(arg[compt->i]);
		g_env.commande[compt->j].argv[++compt->k] = ft_strdup(arg[compt->i]);
	}
	else
		arg_to_struct2(arg, compt);
}

int	arg_to_struct(char **arg)
{
	t_compt	compt;
	int		size;

	size = 0;
	compt.j = -1;
	compt.k = -1;
	compt.i = -1;
	if (malloc_struct(&compt.j, &size, arg) == 0)
		return (0);
	while (++compt.i < compt.j - 1)
	{
		g_env.commande[compt.i].argv = malloc(sizeof(void *) * (size + 1));
	}
	compt.i = -1;
	compt.j = -1;
	while (arg[++compt.i])
		gest_if(arg, &compt);
	if (compt.k > -1)
		g_env.commande[compt.j].argv[++compt.k] = NULL;
	g_env.commande[++compt.j].exec = NULL;
	freetab(arg);
	return (1);
}
