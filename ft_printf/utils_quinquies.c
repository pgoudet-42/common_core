/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quinquies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:31:37 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/15 10:55:39 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		creat_char_int(t_chaine chaine, t_arg arg)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < chaine.deb_space)
		ft_putchar(' ');
	j++;
	ft_putchar('-');
	j += i;
	i = -1;
	while (++i < chaine.deb_zero)
		ft_putchar('0');
	j += i;
	i = -1;
	while (++i < chaine.taille_var - 1)
		ft_putchar(arg.arg[i + 1]);
	j += i;
	i = -1;
	while (++i < chaine.end_space)
		ft_putchar(' ');
	j += i;
	return (j);
}

int		ischar_spe(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'd' || c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

int		ischar_var(char c)
{
	if (c == '.' || c == '*' || ft_isdigit(c) == 1 || c == '-')
	{
		return (1);
	}
	return (0);
}

int		varlen(char *tab)
{
	int	i;

	i = 1;
	while (ischar_var(tab[i]) == 1)
		i++;
	i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
