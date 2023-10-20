/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prct.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:34:55 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/16 12:21:20 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		t_chaine_prct(char *spe, t_flag flags, va_list *list)
{
	t_arg		arg;
	t_chaine	chaine;
	int			i;

	free(spe);
	init_tchaine(&chaine);
	arg = extract_arg(list, '%');
	chaine = regle_chr(chaine, flags, arg);
	i = creat_char(chaine, arg);
	return (i);
}
