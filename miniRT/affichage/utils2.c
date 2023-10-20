/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:23:12 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 12:42:49 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

int			sup_oinf(t_eqplan eq, t_point pt)
{
	double p_haute;

	if ((p_haute = (eq.a * pt.x) + (eq.b * pt.y) + (eq.c * pt.z) + eq.d) > 0)
		return (1);
	return (0);
}

t_point		projete_ortho(t_point p, t_vecteur n, t_eqplan eq)
{
	double		dist;
	t_point		p_fin;
	t_vecteur	vf;

	dist = distance_pt_pl(p, eq);
	p_fin.x = p.x;
	p_fin.y = p.y;
	p_fin.z = p.z;
	if (sup_oinf(eq, p) == 0)
	{
		vf.x = n.x;
		vf.y = n.y;
		vf.z = n.z;
	}
	else
	{
		vf.x = -n.x;
		vf.y = -n.y;
		vf.z = -n.z;
	}
	p_fin.x = p_fin.x + (dist * (vf.x / taille_vecteur(vf)));
	p_fin.y = p_fin.y + (dist * (vf.y / taille_vecteur(vf)));
	p_fin.z = p_fin.z + (dist * (vf.z / taille_vecteur(vf)));
	return (p_fin);
}

t_vecteur	vnorm_fpoint(t_vecteur n, t_eqplan eq, t_point p)
{
	t_point		projete_orthogonal;
	t_vecteur	v_fin;

	projete_orthogonal = projete_ortho(p, n, eq);
	v_fin = vecteur(p, projete_orthogonal);
	return (v_fin);
}

double		distance_pt_pt(t_point p_ref, t_point p2)
{
	double distance;
	double x2;
	double y2;
	double z2;

	x2 = pow(p2.x - p_ref.x, 2);
	y2 = pow(p2.y - p_ref.y, 2);
	z2 = pow(p2.z - p_ref.z, 2);
	distance = sqrt(x2 + y2 + z2);
	return (distance);
}

double		isintr(t_point a, t_point b, t_point c, t_point m)
{
	double		res;

	res = 0;
	if (produit_scalaire(produit_vectoriel(vecteur(a, b), vecteur(a, m)),
	produit_vectoriel(vecteur(a, m), vecteur(a, c))) >= 0)
		res += 1;
	if (produit_scalaire(produit_vectoriel(vecteur(b, a), vecteur(b, m)),
	produit_vectoriel(vecteur(b, m), vecteur(b, c))) >= 0)
		res += 2;
	if (produit_scalaire(produit_vectoriel(vecteur(c, a), vecteur(c, m)),
	produit_vectoriel(vecteur(c, m), vecteur(c, b))) >= 0)
		res += 3;
	return (res);
}
