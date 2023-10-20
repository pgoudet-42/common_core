/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sexies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 09:57:43 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/16 15:26:08 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_tchaine(t_chaine *chaine)
{
	chaine->deb_zero = 0;
	chaine->end_space = 0;
	chaine->taille_chaine = 0;
	chaine->taille_var = 0;
	chaine->deb_space = 0;
}

int		creat_char_0(t_chaine chaine)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < chaine.deb_space - 1)
		ft_putchar(' ');
	j += i;
	i = -1;
	while (++i < chaine.deb_zero)
		ft_putchar('0');
	j += i;
	i = -1;
	j++;
	ft_putchar(0);
	while (++i < chaine.end_space - 1)
		ft_putchar(' ');
	j += i;
	return (j);
}

char	*ft_utoa(unsigned int n)
{
	char		*tab;
	long int	l;
	int			i;

	l = (long int)n;
	if (!(tab = malloc(sizeof(char) * ft_nbrlen(l) + 1)))
		return (0);
	if (!tab)
		return (NULL);
	tab[ft_nbrlen(l)] = 0;
	i = ft_nbrlen(l) - 1;
	if (l == -0)
		tab[0] = 48;
	if (l < 0)
		l = -l;
	while (l != 0)
	{
		tab[i] = l % 10 + 48;
		l = l / 10;
		i--;
	}
	return (tab);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_nbrlen_int(int i)
{
	int compt;

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
