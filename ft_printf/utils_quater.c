/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:27:03 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/17 14:37:04 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_bis(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		len;

	i = -1;
	if (!s1)
		return (tab = s2);
	else
		tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!tab)
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i])
		tab[i] = s1[i];
	len = -1;
	while (++len < (int)ft_strlen(s2))
		tab[i + len] = s2[len];
	tab[i + len] = 0;
	free(s1);
	return (tab);
}

char	*itoh_bis(unsigned int nbr, int a)
{
	int						taille_base;
	unsigned long long int	res;
	static int				i;
	char					*dest;
	char					*base;

	if (a == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	res = nbr;
	taille_base = ft_strlen((const char *)base);
	i = 1;
	while ((res = res / taille_base) > 0)
		i++;
	if (!(dest = malloc(sizeof(char) * i)))
		return (0);
	dest[i--] = 0;
	while (nbr >= (unsigned int)taille_base)
	{
		dest[i--] = base[nbr % taille_base];
		nbr = nbr / taille_base;
	}
	dest[i] = base[nbr % taille_base];
	return (dest);
}

char	*isnull(char *tab)
{
	if (tab == 0)
	{
		if (!(tab = malloc(6)))
			return (0);
		tab = "(null)";
		tab[6] = 0;
	}
	return (tab);
}

t_arg	extract_arg(va_list *list, char c)
{
	t_arg argv;

	if (c == 'c')
	{
		if (!(argv.arg = malloc(2)))
			return (argv);
		argv.arg[0] = (char)va_arg(*list, int);
		argv.arg[1] = 0;
	}
	if (c == 's')
		argv.arg = ft_strdup((char *)va_arg(*list, char*));
	if (c == 'p')
		argv.arg = itoh((unsigned long long)va_arg(*list, unsigned long long));
	if (c == 'd' || c == 'i')
		argv.arg = ft_itoa((int)va_arg(*list, int));
	if (c == 'u')
		argv.arg = ft_utoa((unsigned int)va_arg(*list, unsigned int));
	if (c == 'x')
		argv.arg = itoh_bis((int)va_arg(*list, int), 0);
	if (c == 'X')
		argv.arg = itoh_bis((unsigned int)va_arg(*list, unsigned int), 1);
	if (c == '%')
		argv.arg = "%";
	argv.arg = isnull(argv.arg);
	return (argv);
}

int		creat_char(t_chaine chaine, t_arg arg)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < chaine.deb_space)
		ft_putchar(' ');
	j += i;
	i = -1;
	while (++i < chaine.deb_zero)
		ft_putchar('0');
	j += i;
	i = -1;
	while (++i < chaine.taille_var)
		ft_putchar(arg.arg[i]);
	j += i;
	i = -1;
	while (++i < chaine.end_space)
		ft_putchar(' ');
	j += i;
	return (j);
}
