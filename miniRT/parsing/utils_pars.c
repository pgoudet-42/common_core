/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:02:49 by pgoudet           #+#    #+#             */
/*   Updated: 2021/02/13 16:19:04 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

void		init_t_nbtype(t_nbtype *nb_type)
{
	nb_type->r.value = 0;
	nb_type->a.value = 0;
	nb_type->c.value = 0;
	nb_type->l.value = 0;
	nb_type->sp.value = 0;
	nb_type->pl.value = 0;
	nb_type->sq.value = 0;
	nb_type->cy.value = 0;
	nb_type->tr.value = 0;
	nb_type->r.flag_m = 0;
	nb_type->a.flag_m = 0;
	nb_type->c.flag_m = 0;
	nb_type->l.flag_m = 0;
	nb_type->sp.flag_m = 0;
	nb_type->pl.flag_m = 0;
	nb_type->sq.flag_m = 0;
	nb_type->cy.flag_m = 0;
	nb_type->tr.flag_m = 0;
}

int			traitement_id(char *str)
{
	int res;

	res = 0;
	if (str[0] == 'R')
		res = 1;
	else if (str[0] == 'A')
		res = 2;
	else if ((str[0] == 'c' || str[0] == 'C') && space(str[1]) == 1)
		res = 3;
	else if ((str[0] == 'l' || str[0] == 'L') && space(str[1]) == 1)
		res = 4;
	else if ((str[0] == 's' || str[0] == 'S') && str[1] == 'p')
		res = 5;
	else if ((str[0] == 'p' || str[0] == 'P') && str[1] == 'l')
		res = 6;
	else if ((str[0] == 's' || str[0] == 'S') && str[1] == 'q')
		res = 7;
	else if ((str[0] == 'c' || str[0] == 'C') && str[1] == 'y')
		res = 8;
	else if ((str[0] == 't' || str[0] == 'T') && str[1] == 'r')
		res = 9;
	if (res != 'R' && res != 'A')
		res += is_single(str);
	return (res);
}

int			is_single(char *str)
{
	if (str[0] >= 65 && str[0] <= 90)
		return (10);
	return (0);
}

void		trait_type(char *tab, t_obj *obj, int i)
{
	int		res;

	res = traitement_id(tab);
	if (res > 10)
	{
		if (res == i)
		{
			obj->value += 1;
			obj->flag_m = 1;
		}
	}
	else if (res == i && res < 10)
		obj->value += 1;
}

void		nb_type_init(t_nbtype *nb_type, char **tab)
{
	int i;

	i = -1;
	init_t_nbtype(nb_type);
	while (tab[++i])
	{
		trait_type(tab[i], &nb_type->r, 11);
		trait_type(tab[i], &nb_type->a, 12);
		trait_type(tab[i], &nb_type->c, 3);
		trait_type(tab[i], &nb_type->l, 4);
		trait_type(tab[i], &nb_type->pl, 6);
		trait_type(tab[i], &nb_type->sp, 5);
		trait_type(tab[i], &nb_type->sq, 7);
		trait_type(tab[i], &nb_type->cy, 8);
		trait_type(tab[i], &nb_type->tr, 9);
	}
}
