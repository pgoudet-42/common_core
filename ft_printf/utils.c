/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:08:20 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/15 17:06:47 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_nbrlen(unsigned long long int i)
{
	unsigned int compt;

	compt = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		compt++;
	while (i != 0)
	{
		compt++;
		i = i / 10;
	}
	return (compt);
}

unsigned int	ft_nbrlen_hexa(unsigned int i)
{
	unsigned int compt;

	compt = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		compt++;
	while (i != 0)
	{
		compt++;
		i = i / 16;
	}
	return (compt);
}

int				find_chr(char *tab, char chr)
{
	int i;

	i = 0;
	while (tab[i] != chr && tab[i])
		i++;
	return (i);
}

int				chr_spe(char *tab)
{
	int i;

	i = 0;
	while ((ischar_spe(tab[i]) == 1 || ft_isdigit(tab[i]) == 1 ||
	is_char_op(tab[i]) != 0 || tab[i] == '*') && tab[i])
	{
		if (tab[i] == 'c')
			return (i);
		if (tab[i] == 's')
			return (i);
		if (tab[i] == 'p')
			return (i);
		if (tab[i] == 'd' || tab[i] == 'i')
			return (i);
		if (tab[i] == 'u')
			return (i);
		if (tab[i] == 'x')
			return (i);
		if (tab[i] == 'X')
			return (i);
		if (tab[i] == '%')
			return (i);
		i++;
	}
	return (i);
}

int				is_char_op(char c)
{
	if (c == '0' || c == '.' || c == '-')
	{
		return ((int)c);
	}
	return (0);
}
