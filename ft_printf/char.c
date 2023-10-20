/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 09:07:43 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/15 15:40:21 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_chaine	regle_chr(t_chaine chaine, t_flag flags, t_arg arg)
{
	chaine.taille_var = ft_strlen(arg.arg);
	chaine.taille_chaine += chaine.taille_var;
	if (chaine.taille_chaine < flags.flag_m.value)
		chaine.end_space += flags.flag_m.value - chaine.taille_chaine;
	chaine.taille_chaine += chaine.end_space;
	if (chaine.taille_chaine < flags.flag_0.value)
		chaine.deb_zero += flags.flag_0.value - chaine.taille_chaine;
	chaine.taille_chaine += chaine.deb_zero;
	if (chaine.taille_chaine < flags.flag_l.value)
		chaine.deb_space += flags.flag_l.value - chaine.taille_chaine;
	if (flags.flag_l.value < 0)
		chaine.end_space += (-flags.flag_l.value) - chaine.taille_var;
	chaine.taille_chaine += chaine.deb_space;
	return (chaine);
}

int			t_chaine_chr(char *spe, t_flag flags, va_list *list)
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
	chaine = regle_chr(chaine, flags, arg);
	if (arg.arg[0] == 0)
		i = creat_char_0(chaine);
	else
		i = creat_char(chaine, arg);
	free(arg.arg);
	free(spe);
	return (i);
}
