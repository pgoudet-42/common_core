/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:23:49 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 13:32:20 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

int			is_between(t_point p, t_sq sq)
{
	int res;

	res = 0;
	if (isintr(sq.p, sq.p2, sq.p3, p) == 6
	|| isintr(sq.p, sq.p3, sq.p4, p) == 6)
		res += 10;
	return (res);
}

void		normalisation_couleurs(t_color *c)
{
	c->r = c->r / 255;
	c->g = c->g / 255;
	c->b = c->b / 255;
}

void		normalisation_vecteurs(t_vecteur *v)
{
	double taille;

	taille = taille_vecteur(*v);
	v->x = v->x / taille;
	v->y = v->y / taille;
	v->z = v->z / taille;
}
