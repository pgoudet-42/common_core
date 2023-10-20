/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:35:52 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/15 14:37:04 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	t_chaine_error(char *spe, t_flag flags, va_list *list)
{
	int a;

	flags.flag_p.value = 0;
	if (list)
		a = 1;
	free(spe);
	return (0);
}
