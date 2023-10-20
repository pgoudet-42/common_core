/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:10:00 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/15 17:16:12 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_caracteristique	value_to_flag(char *tab, char c, va_list list, int *i)
{
	t_caracteristique flag;

	flag.flag = 0;
	flag.value = 0;
	while (is_char_op(tab[*i]) == c)
	{
		flag.flag = 1;
		*i += 1;
	}
	if (flag.flag == 1 && tab[*i] == '*')
	{
		flag.value = is_etoile(tab, list);
		*i += 1;
	}
	else if (flag.flag == 1)
	{
		flag.value = ft_atoi(&tab[*i]);
		if (flag.value != 0)
			*i += ft_nbrlen_int(flag.value);
	}
	return (flag);
}

void				init_flags(t_flag *flag)
{
	flag->flag_0.flag = 0;
	flag->flag_m.flag = 0;
	flag->flag_p.flag = 0;
	flag->flag_l.flag = 0;
	flag->flag_0.value = 0;
	flag->flag_m.value = 0;
	flag->flag_p.value = 0;
	flag->flag_l.value = 0;
}

t_flag				trait_op(char *spe, va_list list)
{
	t_flag	flags;
	int		i;
	int		j;

	j = 0;
	i = 0;
	init_flags(&flags);
	flags.flag_l = value_larg_min(spe, list, &i);
	while (is_char_op(spe[i]) != 0 && spe[i] && j < 3)
	{
		if (flags.flag_m.flag == 0)
			flags.flag_m = value_to_flag(spe, '-', list, &i);
		if (flags.flag_p.flag == 0)
			flags.flag_p = value_to_flag(spe, '.', list, &i);
		if (flags.flag_0.flag == 0)
			flags.flag_0 = value_to_flag(spe, '0', list, &i);
		j++;
	}
	flags = exceptions_t_op(flags);
	flags = exceptions_t_op_bis(flags);
	return (flags);
}

t_flag				exceptions_t_op(t_flag flags)
{
	if (flags.flag_0.value < 0)
	{
		flags.flag_m.value = -flags.flag_0.value;
		flags.flag_0.value = 0;
	}
	if (flags.flag_p.value < 0 && flags.flag_p.flag != 1)
	{
		flags.flag_m.value = flags.flag_p.value;
		flags.flag_p.value = 0;
	}
	if (flags.flag_m.flag != 0)
	{
		if (flags.flag_0.value > flags.flag_m.value && flags.flag_0.flag != 0)
		{
			flags.flag_m.value = flags.flag_0.value;
			flags.flag_0.value = 0;
		}
		else
			flags.flag_0.value = 0;
	}
	return (flags);
}

t_flag				exceptions_t_op_bis(t_flag flags)
{
	if (flags.flag_m.value > 1 || flags.flag_0.flag != 0)
		flags.flag_l.flag = 0;
	if (flags.flag_l.flag == 1 && flags.flag_l.value < 0)
	{
		flags.flag_m.value = flags.flag_l.value;
		flags.flag_m.flag = 1;
		flags.flag_l.value = 0;
	}
	if (flags.flag_m.value < 0)
		flags.flag_m.value = -flags.flag_m.value;
	return (flags);
}
