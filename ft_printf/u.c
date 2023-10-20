/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:52:20 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/16 12:51:37 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			t_chaine_u(char *spe, t_flag flags, va_list *list)
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
