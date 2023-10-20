/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:07:34 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/17 14:32:17 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_chaine	regle_i_bis(t_chaine chaine, t_flag flags, t_arg arg)
{
	if (chaine.taille_chaine < flags.flag_0.value)
	{
		if (flags.flag_p.value < flags.flag_0.value && flags.flag_p.value != 0)
			chaine.deb_space += flags.flag_0.value - chaine.taille_chaine;
		else
			chaine.deb_zero += flags.flag_0.value - chaine.taille_chaine;
	}
	if (flags.flag_p.value == 0 && flags.flag_p.flag == 1)
	{
		chaine.deb_space += chaine.deb_zero;
		if (arg.arg[0] == '0')
		{
			if (chaine.end_space != 0)
				chaine.end_space += chaine.taille_var;
			chaine.taille_var = 0;
			if (chaine.deb_space != 0)
				chaine.deb_space += 1;
		}
		chaine.deb_zero = 0;
	}
	chaine.taille_chaine += chaine.deb_zero;
	return (chaine);
}

t_chaine	regle_i(t_chaine chaine, t_flag flags, t_arg arg)
{
	chaine.taille_var = ft_strlen(arg.arg);
	chaine.taille_chaine += chaine.taille_var;
	if (chaine.taille_var < flags.flag_p.value && arg.flag == 0)
		chaine.deb_zero += flags.flag_p.value - chaine.taille_var;
	if (chaine.taille_var <= flags.flag_p.value && arg.flag == 1)
		chaine.deb_zero += flags.flag_p.value - chaine.taille_var + 1;
	chaine.taille_chaine += chaine.deb_zero;
	if (chaine.taille_chaine < flags.flag_l.value)
		chaine.deb_space += flags.flag_l.value - chaine.taille_chaine;
	chaine.taille_chaine += chaine.deb_space;
	if (chaine.taille_chaine < flags.flag_m.value)
		chaine.end_space += flags.flag_m.value - chaine.taille_chaine;
	chaine.taille_chaine += chaine.end_space;
	chaine = regle_i_bis(chaine, flags, arg);
	if ((flags.flag_l.value == 1 || flags.flag_m.value == 1
	|| flags.flag_0.value == 1)
	&& arg.arg[0] == '0' && flags.flag_p.flag == 1 && flags.flag_p.value == 0)
		chaine.deb_space = 1;
	return (chaine);
}

int			t_chaine_i(char *spe, t_flag flags, va_list *list)
{
	int			i;
	t_chaine	chaine;
	t_arg		arg;

	i = 0;
	init_tchaine(&chaine);
	while ((ft_isdigit(spe[i]) == 1 || is_char_op(spe[i]) != 0 ||
	spe[i] == '*') && spe[i])
		i++;
	arg = extract_arg(list, spe[i]);
	if (arg.arg[0] == '-')
		arg.flag = 1;
	else
		arg.flag = 0;
	chaine = regle_i(chaine, flags, arg);
	if (arg.arg[0] == '-')
		i = creat_char_int(chaine, arg);
	else
		i = creat_char(chaine, arg);
	free(spe);
	free(arg.arg);
	return (i);
}
