/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_quater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:21:57 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/28 11:25:53 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

double		cos1(double nb)
{
	double res;
	double angle;

	angle = nb * 0.01745353;
	res = cos(angle);
	return (res);
}

double		sin1(double nb)
{
	double res;
	double angle;

	angle = nb * 0.01745353;
	res = sin(angle);
	return (res);
}

double		angle_surx(t_vecteur u)
{
	t_vecteur	x;

	x.x = 1;
	x.y = 0;
	x.z = 0;
	return (angle_uv(u, x));
}

double		angle_sury(t_vecteur u)
{
	t_vecteur	y;

	y.x = 0;
	y.y = 1;
	y.z = 0;
	return (angle_uv(u, y));
}

double		angle_surz(t_vecteur u)
{
	t_vecteur	z;

	z.x = 0;
	z.y = 0;
	z.z = 1;
	return (angle_uv(u, z));
}
