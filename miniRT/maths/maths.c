/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 09:48:31 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/27 15:00:05 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

t_vecteur	vecteur(t_point a, t_point b)
{
	t_vecteur v;

	v.x = (b.x - a.x);
	v.y = (b.y - a.y);
	v.z = (b.z - a.z);
	return (v);
}

t_vecteur	produit_vectoriel(t_vecteur u, t_vecteur v)
{
	t_vecteur u_pv_v;

	u_pv_v.x = (u.z * v.y) - (u.y * v.z);
	u_pv_v.y = (u.x * v.z) - (u.z * v.x);
	u_pv_v.z = (u.y * v.x) - (u.x * v.y);
	return (u_pv_v);
}

double		produit_scalaire(t_vecteur v, t_vecteur u)
{
	double res;

	res = (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
	return (res);
}

double		max(double a, double b, double c)
{
	if (a >= b && a >= c)
		return (a);
	if (b >= a && b >= c)
		return (b);
	if (c >= b && c >= a)
		return (c);
	return (0);
}

double		min(double a, double b, double c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	if (c <= b && c <= a)
		return (c);
	return (0);
}
