/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 09:51:56 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 12:48:51 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

int		equ_sp(t_point *pt, t_point centre, double diam)
{
	int res;

	res = 0;
	if ((pow((pt->x - centre.x), 2) + pow((pt->y - centre.y), 2)
	+ pow((pt->z - centre.z), 2)) <= pow((diam / 2), 2))
		res = 1;
	return (res);
}

double	taille_vecteur(t_vecteur v)
{
	double res;

	res = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	return (res);
}

double	angle_uv(t_vecteur v, t_vecteur u)
{
	double res;
	double part_bas;

	part_bas = taille_vecteur(v) * taille_vecteur(u);
	if (part_bas == 0)
		return (0);
	res = acos(produit_scalaire(v, u) / part_bas);
	res = res * 57.295;
	return (res);
}

int		check_eqpl(t_pl pl, t_point p)
{
	if (pl.eq.a * p.x + pl.eq.b * p.y + pl.eq.c * p.z + pl.eq.d == 0)
		return (1);
	return (0);
}
