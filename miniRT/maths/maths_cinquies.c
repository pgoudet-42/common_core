/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_cinquies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:56:25 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 12:49:08 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

t_point		p_fois_v(t_point pt, t_vecteur v, double t)
{
	pt.x = pt.x + t * v.x;
	pt.y = pt.y + t * v.y;
	pt.z = pt.z + t * v.z;
	return (pt);
}

void		ymin_ymax_sq(double *ymin, double *ymax, t_sq sq)
{
	int		i;
	double	tab[4];

	i = -1;
	tab[0] = sq.p.y;
	tab[1] = sq.p2.y;
	tab[2] = sq.p3.y;
	tab[3] = sq.p4.y;
	*ymin = sq.p.y;
	while (++i < 4)
		if (*ymin > tab[i])
			*ymin = tab[i];
	i = -1;
	while (++i < 4)
		if (*ymax < tab[i])
			*ymax = tab[i];
}

t_vecteur	v_from_eq(t_eqplan eq)
{
	t_vecteur v;

	v.x = eq.a;
	v.y = eq.b;
	v.z = eq.c;
	return (v);
}

t_vecteur	addition_vecteurs(t_vecteur v1, t_vecteur v2)
{
	t_vecteur v_res;

	v_res.x = v1.x + v2.x;
	v_res.y = v1.y + v2.y;
	v_res.z = v1.z + v2.z;
	v_res.x = v_res.x + taille_vecteur(v_res);
	v_res.y = v_res.y + taille_vecteur(v_res);
	v_res.z = v_res.z + taille_vecteur(v_res);
	return (v_res);
}

t_vecteur	moins_v(t_vecteur v)
{
	t_vecteur u;

	u.x = -v.x;
	u.y = -v.y;
	u.z = -v.z;
	return (u);
}
