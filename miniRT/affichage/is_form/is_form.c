/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:15:37 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 12:37:19 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.h"

t_point	is_cy(t_droite d, t_cy *cy)
{
	double	t;
	t_point	inter;

	t = find_ptcommun_cy3(d, cy);
	inter.check[0] = '\0';
	if (t == -1)
		return (inter);
	inter.x = t * d.v.x + d.p.x;
	inter.y = t * d.v.y + d.p.y;
	inter.z = t * d.v.z + d.p.z;
	cy->eq_p = eq_plan2(cy->v_or, cy->p);
	cy->eq_p_opp = eq_plan2(moins_v(cy->v_or), cy->p_opp);
	if ((cy->eq_p.a * inter.x + cy->eq_p.b * inter.y + cy->eq_p.c * inter.z
	+ cy->eq_p.d <= 0 && cy->eq_p_opp.a * inter.x + cy->eq_p_opp.b * inter.y
	+ cy->eq_p_opp.c * inter.z + cy->eq_p_opp.d >= 0)
	|| (cy->eq_p.a * inter.x + cy->eq_p.b * inter.y + cy->eq_p.c * inter.z +
	cy->eq_p.d >= 0 && cy->eq_p_opp.a * inter.x + cy->eq_p_opp.b * inter.y +
	cy->eq_p_opp.c * inter.z + cy->eq_p_opp.d <= 0))
		return (inter);
	inter.check[0] = '1';
	inter.check[1] = '\0';
	return (inter);
}

t_point	is_sphere(t_sp *sp, t_droite d)
{
	double	t;
	t_point p;

	p.check[0] = '\0';
	t = find_ptcommun_sp(d, sp);
	if (t < 0)
		return (p);
	p.x = t * d.v.x + d.p.x;
	p.y = t * d.v.y + d.p.y;
	p.z = t * d.v.z + d.p.z;
	p.check[0] = '1';
	p.check[1] = '\0';
	return (p);
}

t_point	is_tr(t_droite d, t_tr *tr)
{
	t_point inter;

	tr->pl.eq = eq_plan(tr->p1, tr->p2, tr->p3);
	inter = inter_pl(d, &tr->pl);
	inter.check[0] = '\0';
	if (inter.x == d.p.x && inter.y == d.p.y && inter.z == d.p.z)
		return (inter);
	if (isintr(tr->p1, tr->p2, tr->p3, inter) == 6)
	{
		inter.check[0] = '1';
		inter.check[1] = '\0';
		return (inter);
	}
	return (inter);
}

t_point	is_sq(t_droite d, t_sq *sq)
{
	t_point	inter;

	inter.x = 0;
	inter.y = 0;
	inter.z = 0;
	inter.check[0] = '\0';
	init_sq(sq);
	inter = inter_pl(d, &sq->pl);
	if (inter.x == d.p.x && inter.y == d.p.y && inter.z == d.p.z)
		return (inter);
	if (is_between(inter, *sq) >= 1)
	{
		inter.check[0] = '1';
		inter.check[1] = '\0';
		return (inter);
	}
	return (inter);
}

t_point	is_pl(t_droite d, t_pl *pl)
{
	t_point	inter;

	pl->eq = eq_plan2(pl->v_or, pl->p);
	inter = inter_pl(d, pl);
	inter.check[0] = '\0';
	if (inter.x == d.p.x && inter.y == d.p.y && inter.z == d.p.z)
		return (inter);
	inter.check[0] = '1';
	inter.check[1] = '\0';
	return (inter);
}
