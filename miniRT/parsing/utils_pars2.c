/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:58:42 by pgoudet           #+#    #+#             */
/*   Updated: 2021/02/13 15:40:23 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

int	is_id(char *c)
{
	int i;

	i = -1;
	if ((c[0] == 'R' && space(c[1]) == 1)
	|| (c[0] == 'A' && space(c[1]) == 1) ||
	(c[0] == 'c' && space(c[1]) == 1) || (c[0] == 'C' && space(c[1]) == 1) ||
	(c[0] == 'l' && space(c[1]) == 1) || (c[0] == 'L' && space(c[1]) == 1) ||
	(c[0] == 'c' && c[1] == 'y') || (c[0] == 'C' && c[1] == 'y') ||
	(c[0] == 'p' && c[1] == 'l') || (c[0] == 'P' && c[1] == 'l') ||
	(c[0] == 's' && c[1] == 'p') || (c[0] == 'S' && c[1] == 'p') ||
	(c[0] == 's' && c[1] == 'q') || (c[0] == 'S' && c[1] == 'q') ||
	(c[0] == 't' && c[1] == 'r') || (c[0] == 'T' && c[1] == 'r'))
		return (1);
	return (0);
}

int	too_val(char **tab)
{
	int i;
	int j;
	int id;

	i = 0;
	j = 1;
	while (tab[i])
	{
		id = traitement_id(tab[i]);
		if (id >= 10)
		{
			while (tab[j])
			{
				if (j == i && tab[j + 1])
					j++;
				if (id == traitement_id(tab[j])
				|| id == (traitement_id(tab[j]) + 10))
					return (-1);
				j++;
			}
		}
		i++;
		j = 1;
	}
	return (0);
}

int	check_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 2;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if ((space(tab[i][j]) == 0) && tab[i][j] != '-' &&
			ft_isdigit(tab[i][j]) == 0 && tab[i][j] != '.' &&
			tab[i][j] != ',')
				return (-1);
			if (tab[i][j] == '.')
				if (ft_isdigit(tab[i][j + 1]) != 1)
					return (-1);
			j++;
		}
		j = 2;
		i++;
	}
	return (0);
}

int	space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	check_error(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		if (is_id(tab[i]) == 0)
			return (-1);
	if (too_val(tab) != 0)
		return (-2);
	if (check_tab(tab) != 0)
		return (-3);
	if (check_filling(tab) != 0)
		return (-4);
	return (0);
}
