/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 13:31:36 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 12:40:00 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

t_point		projete_ortho_dr(t_droite d, t_point pt)
{
	double	a;
	double	c;
	double	discriminant;
	double	t;
	t_point p;

	p.x = -1;
	p.y = -1;
	p.z = -1;
	a = -pow(d.v.x, 2) - pow(d.v.y, 2) - pow(d.v.z, 2);
	c = (d.v.x * (pt.x - d.p.x)) + (d.v.y * (pt.y - d.p.y)) +
	(d.v.z * (pt.z - d.p.z));
	discriminant = -4 * a * c;
	if (discriminant < 0)
		return (p);
	t = -sqrt(discriminant) / (2 * a);
	p.x = d.p.x + t * d.v.x;
	p.y = d.p.y + t * d.v.y;
	p.z = d.p.z + t * d.v.z;
	return (p);
}

void		init_point(t_point *p, double x, double y, double z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

void		init_vecteur(t_vecteur *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void		init_color(t_color *c, double x, double y, double z)
{
	c->r = x;
	c->g = y;
	c->b = z;
}
