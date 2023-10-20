/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 08:59:29 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/15 15:57:52 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_bis(int *i, int *j, int *ct, const char *str)
{
	*i = 0;
	*j = 0;
	*ct = 0;
	if (ft_strlen(str) == 0)
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list		list;
	char		*spe;
	int			i;
	int			j;
	int			ct;

	va_start(list, str);
	if (ft_printf_bis(&i, &j, &ct, str) == 0)
		return (0);
	while (i < (int)ft_strlen(str))
	{
		i += find_chr((char *)&str[i], '%');
		ct += i - j;
		ft_putstr(spe = ft_substr(str, j, i - j));
		free(spe);
		if (i < (int)ft_strlen(str))
		{
			spe = ft_substr(str, (unsigned int)i + 1,
			chr_spe((char *)&str[i + 1]) + 1);
			ct += good_fnct(spe[chr_spe(spe)])(spe, trait_op(spe, list), &list);
			j = i += varlen((char *)&str[i]);
		}
	}
	va_end(list);
	return (ct);
}
