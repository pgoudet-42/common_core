/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:12:08 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 12:38:39 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.h"

t_vecteur	vecteur_ctr_p(t_point pt, t_cy cy)
{
	t_point		projete;
	t_vecteur	v;

	projete = p_fois_v(pt, moins_v(cy.v_or), distance_pt_pl(pt, cy.eq_p));
	v = vecteur(cy.p, projete);
	return (v);
}

void		take_info(t_cy cy, t_inter *inter, t_point pt_check, t_droite d)
{
	double		dist_pl;
	t_vecteur	v;

	dist_pl = distance_pt_pt(d.p, pt_check);
	if (inter->dist > dist_pl)
	{
		inter->p = pt_check;
		inter->color = cy.color;
		inter->dist = dist_pl;
		inter->check[0] = '1';
		inter->check[1] = '0';
		inter->d_ray = d;
		v = vecteur_ctr_p(inter->p, cy);
		normalisation_vecteurs(&v);
		inter->eq = eq_plan2(v, pt_check);
	}
}

void		take_info2(t_sq sq, t_inter *inter, t_point pt_check, t_droite d)
{
	double dist_pl;

	dist_pl = distance_pt_pt(d.p, pt_check);
	if (inter->dist > dist_pl)
	{
		inter->p = pt_check;
		inter->color = sq.color;
		inter->dist = dist_pl;
		inter->check[0] = '1';
		inter->check[1] = '0';
		inter->d_ray = d;
		inter->eq = sq.pl.eq;
	}
}
