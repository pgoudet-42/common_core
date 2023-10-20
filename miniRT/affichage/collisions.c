/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:59:52 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/28 09:55:27 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

double	find_ptcommun_sp(t_droite d, t_sp *sp)
{
	double		part_a;
	double		part_b;
	double		part_c;
	double		t;
	t_vecteur	e;

	e.x = d.p.x - sp->p.x;
	e.y = d.p.y - sp->p.y;
	e.z = d.p.z - sp->p.z;
	part_a = produit_scalaire(d.v, d.v);
	part_b = 2 * produit_scalaire(d.v, e);
	part_c = produit_scalaire(e, e) - pow((sp->diam / 2), 2);
	t = eq_2deg(part_a, part_b, part_c);
	return (t);
}

double	find_ptcommun_pl(t_droite d, t_pl pl)
{
	double t;
	double part_b;
	double part_c;

	part_b = (pl.eq.a * d.v.x) + (pl.eq.b * d.v.y) + (pl.eq.c * d.v.z);
	part_c = (pl.eq.a * d.p.x) + (pl.eq.b * d.p.y) +
	(pl.eq.c * d.p.z) + pl.eq.d;
	if (part_b == 0)
		return (-1);
	t = -part_c / part_b;
	return (t);
}

double	find_ptcommun_cy3(t_droite d, t_cy *cy)
{
	t_droite	new_d;
	t_cy		new_cy;
	double		angley;
	double		anglez;
	t_point		p_temp;

	angley = -1;
	anglez = -1;
	init_cy_values(cy);
	new_cy.v_or = calcul_matriciel(cy->v_or, &angley, &anglez);
	normalisation_vecteurs(&new_cy.v_or);
	new_cy.p = calcul_matriciel3(cy->p, angley, anglez);
	p_temp = new_cy.p;
	init_point(&new_cy.p, 0, 0, 0);
	new_d.v = calcul_matriciel4(d.v, angley, anglez);
	new_d.p = calcul_matriciel3(d.p, angley, anglez);
	init_point(&new_d.p, new_d.p.x - p_temp.x,
	new_d.p.y - p_temp.y, new_d.p.z - p_temp.z);
	return (eq_2deg(pow(new_d.v.x, 2) + pow(new_d.v.y, 2), 2 *
	(new_d.v.x * new_d.p.x + new_d.v.y * new_d.p.y), pow(new_d.p.x, 2)
	+ pow(new_d.p.y, 2) - pow(cy->diam / 2, 2)));
}

int		check_sp(t_point p, t_sp sp)
{
	if (pow(p.x - sp.p.x, 2) + pow(p.y - sp.p.y, 2)
	+ pow(p.z - sp.p.z, 2) - pow(sp.diam / 2, 2) <= 0)
		return (1);
	return (0);
}
