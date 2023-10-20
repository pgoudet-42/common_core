/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_ter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 10:49:41 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/28 11:25:55 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

t_eqplan	eq_plan(t_point p1, t_point p2, t_point p3)
{
	t_vecteur	n;
	t_vecteur	p1p2;
	t_vecteur	p1p3;
	t_eqplan	eq;

	p1p3 = vecteur(p1, p3);
	p1p2 = vecteur(p1, p2);
	n = produit_vectoriel(p1p2, p1p3);
	eq.a = n.x;
	eq.b = n.y;
	eq.c = n.z;
	eq.d = (-p1.x * n.x) + (-p1.y * n.y) + (-p1.z * n.z);
	return (eq);
}

t_eqplan	eq_plan2(t_vecteur n, t_point p)
{
	t_eqplan eq;

	eq.a = n.x;
	eq.b = n.y;
	eq.c = n.z;
	eq.d = (-p.x * n.x) + (-p.y * n.y) + (-p.z * n.z);
	return (eq);
}

double		distance_pt_pl(t_point pt, t_eqplan eq)
{
	double dist;
	double p_haute;
	double p_basse;

	p_haute = (eq.a * pt.x) + (eq.b * pt.y) + (eq.c * pt.z) + eq.d;
	if (p_haute < 0)
		p_haute = -p_haute;
	p_basse = sqrt(pow(eq.a * eq.a, 2) + pow(eq.b * eq.b, 2)
	+ pow(eq.c * eq.c, 2));
	dist = p_haute / p_basse;
	return (dist);
}

double		angle_horiz(t_vecteur v)
{
	double		angle;
	t_vecteur	u;

	u.x = 1;
	u.y = 0;
	u.z = 0;
	angle = produit_scalaire(v, u) / (taille_vecteur(u) * taille_vecteur(v));
	angle = acos(angle);
	return (angle);
}

double		distance(double start, double end)
{
	double dist;

	dist = end - start;
	if (dist < 0)
		dist = -dist;
	return (dist);
}
