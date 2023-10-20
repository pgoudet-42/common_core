/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:30:11 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/17 14:37:34 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					type_flag(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (0);
	if (c == 'p')
		return (2);
	if (c == 'd' || c == 'i')
		return (3);
	if (c == 'u')
		return (4);
	if (c == 'x')
		return (5);
	if (c == 'X')
		return (5);
	if (c == '%')
		return (6);
	return (7);
}

t_taille_chaine		good_fnct(char c)
{
	t_taille_chaine	f[8];
	int				i;

	f[0] = t_chaine_str;
	f[1] = t_chaine_chr;
	f[2] = t_chaine_adrss;
	f[3] = t_chaine_i;
	f[4] = t_chaine_u;
	f[5] = t_chaine_x;
	f[6] = t_chaine_prct;
	f[7] = t_chaine_error;
	i = type_flag(c);
	return (f[i]);
}

char				*itoh(unsigned long long int nbr)
{
	int						taille_base;
	unsigned long long int	res;
	static int				i;
	char					*dest;
	char					*base;

	base = "0123456789abcdef";
	res = nbr;
	taille_base = ft_strlen(base);
	i = 3;
	while ((res = res / taille_base) > 0)
		i++;
	if (!(dest = malloc(sizeof(char) * i)))
		return (0);
	dest[i--] = 0;
	while (nbr >= (unsigned long long int)taille_base)
	{
		dest[i--] = base[nbr % taille_base];
		nbr = nbr / taille_base;
	}
	dest[i] = base[nbr % taille_base];
	dest[i - 1] = 'x';
	dest[i - 2] = '0';
	return (dest);
}

int					is_etoile(char *tab, va_list list)
{
	int	i;

	i = 0;
	while (tab[i] != '*')
	{
		i++;
		if (i == (int)ft_strlen((const char *)tab))
			return (0);
	}
	return ((int)va_arg(list, int));
}

t_caracteristique	value_larg_min(char *tab, va_list list, int *i)
{
	t_caracteristique flag;

	flag.value = 0;
	if (ft_isdigit(tab[0]) == 1 && tab[0] != '0')
	{
		flag.value = ft_atoi(tab);
		*i += ft_nbrlen(flag.value);
	}
	if (tab[0] == '*')
	{
		flag.value = (int)va_arg(list, int);
		*i += 1;
	}
	if (flag.value != 0)
		flag.flag = 1;
	return (flag);
}
