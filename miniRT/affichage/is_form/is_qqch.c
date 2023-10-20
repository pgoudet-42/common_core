/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_qqch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:11:03 by pgoudet           #+#    #+#             */
/*   Updated: 2021/02/03 09:15:27 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.h"

void	is_qqch5(t_type *type, t_droite d, t_inter *inter)
{
	int		i;
	t_point	pt_check;
	double	dist_pl;

	i = -1;
	while (type->sp[++i].check[0] == '1')
	{
		pt_check = is_sphere(&type->sp[i], d);
		if (pt_check.check[0] == '1')
		{
			dist_pl = distance_pt_pt(d.p, pt_check);
			if (inter->dist > dist_pl)
			{
				inter->p = pt_check;
				inter->color = type->sp[i].color;
				inter->dist = dist_pl;
				inter->check[0] = '1';
				inter->check[1] = '0';
				inter->d_ray = d;
				inter->eq = eq_plan2(vecteur(type->sp[i].p,
				inter->p), inter->p);
			}
		}
	}
}

void	is_qqch4(t_type *type, t_droite d, t_inter *inter)
{
	int			i;
	t_point		pt_check;

	i = -1;
	while (type->cy[++i].check[0] == '1')
	{
		pt_check = is_cy(d, &type->cy[i]);
		if (pt_check.check[0] == '1')
			take_info(type->cy[i], inter, pt_check, d);
	}
}

void	is_qqch3(t_type *type, t_droite d, t_inter *inter)
{
	int		i;
	double	dist_pl;
	t_point pt_check;

	i = -1;
	while (type->tr[++i].check[0] == '1')
	{
		pt_check = is_tr(d, &type->tr[i]);
		if (pt_check.check[0] == '1')
		{
			dist_pl = distance_pt_pt(d.p, pt_check);
			if (inter->dist > dist_pl)
			{
				inter->p = pt_check;
				inter->color = type->tr[i].color;
				inter->dist = dist_pl;
				inter->check[0] = '1';
				inter->check[1] = '0';
				inter->d_ray = d;
				inter->eq = type->tr[i].pl.eq;
			}
		}
	}
}

void	is_qqch2(t_type *type, t_droite d, t_inter *inter)
{
	int		i;
	double	dist_pl;
	t_point pt_check;

	i = -1;
	while (type->pl[++i].check[0] == '1')
	{
		pt_check = is_pl(d, &type->pl[i]);
		if (pt_check.check[0] == '1')
		{
			dist_pl = distance_pt_pt(d.p, pt_check);
			if (inter->dist > dist_pl)
			{
				inter->p = pt_check;
				inter->color = type->pl[i].color;
				inter->dist = dist_pl;
				inter->check[0] = '1';
				inter->check[1] = '0';
				inter->d_ray = d;
				inter->eq = type->pl[i].eq;
			}
		}
	}
}

t_inter	is_qqch(t_type *type, t_droite d, double dist_lum)
{
	int		i;
	t_point pt_check;
	t_inter	inter;

	i = -1;
	inter.dist = dist_lum;
	inter.check[0] = 0;
	while (type->sq[++i].check[0] == '1')
	{
		pt_check = is_sq(d, &type->sq[i]);
		if (pt_check.check[0] == '1')
			take_info2(type->sq[i], &inter, pt_check, d);
	}
	is_qqch2(type, d, &inter);
	is_qqch3(type, d, &inter);
	is_qqch4(type, d, &inter);
	is_qqch5(type, d, &inter);
	if (inter.dist == dist_lum)
		inter.dist = -1;
	return (inter);
}
