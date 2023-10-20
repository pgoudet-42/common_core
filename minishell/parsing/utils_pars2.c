/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:17:00 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/21 16:38:59 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_inquote3(int *posdq, int pos_c)
{
	int	size;
	int	i;

	size = 0;
	i = -1;
	if (posdq)
	{
		while (posdq[size] != -1)
			size++;
		while (++i < size)
			if (pos_c > posdq[i] && pos_c < posdq[++i])
				return (2);
	}
	return (0);
}

int	is_inquote2(int *posq, int pos_c)
{
	int	size;
	int	i;

	size = 0;
	i = -1;
	if (posq)
	{
		while (posq[size] != -1)
			size++;
		while (++i < size)
			if (pos_c > posq[i] && pos_c < posq[++i])
				return (1);
	}
	return (0);
}

int	is_inquote(int pos_c, char *arg)
{
	int	*posdq;
	int	*posq;

	posq = pos_quote(arg);
	posdq = pos_dquote(arg);
	if (is_inquote2(posq, pos_c) == 1)
	{
		free(posdq);
		free(posq);
		return (1);
	}
	if (is_inquote3(posdq, pos_c) == 2)
	{
		free(posdq);
		free(posq);
		return (2);
	}
	free(posdq);
	free(posq);
	return (0);
}

int	*pos_dquote(char *arg)
{
	int	*tab;
	int	i;
	int	compt;

	i = -1;
	compt = 0;
	while (arg[++i])
		if (arg[i] == 34)
			if (i == 0 || (i > 0 && bsvalid(arg, i) == 0))
				compt++;
	tab = malloc(sizeof(int) * (compt + 1));
	if (!tab)
		return (NULL);
	compt = -1;
	i = -1;
	while (arg[++i])
		if (arg[i] == 34)
			if (i == 0 || (i > 0 && bsvalid(arg, i) == 0))
				tab[++compt] = i;
	tab[++compt] = -1;
	return (tab);
}

int	*pos_quote(char *arg)
{
	int	*tab;
	int	i;
	int	compt;

	i = -1;
	compt = 0;
	while (arg[++i])
		if (arg[i] == 39)
			if ((i == 0) || (i > 0 && bsvalid(arg, i) == 0))
				compt++;
	tab = malloc(sizeof(int) * (compt + 1));
	if (!tab)
		return (NULL);
	compt = -1;
	i = -1;
	while (arg[++i])
		if (arg[i] == 39)
			if ((i == 0) || (i > 0 && bsvalid(arg, i) == 0))
				tab[++compt] = i;
	tab[++compt] = -1;
	return (tab);
}
