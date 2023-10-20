/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:14:37 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/27 15:27:21 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

static int			nb_0(double a, double b, double c)
{
	if (a == 0 && b != 0 && c != 0)
		return (11);
	if (a != 0 && b == 0 && c != 0)
		return (12);
	if (a != 0 && b != 0 && c == 0)
		return (13);
	if (a == 0 && b == 0 && c != 0)
		return (21);
	if (a == 0 && b != 0 && c == 0)
		return (22);
	if (a != 0 && b == 0 && c == 0)
		return (23);
	if (a != 0 && b != 0 && c != 0)
		return (30);
	return (-1);
}

static t_vecteur	v_10(int res)
{
	t_vecteur n;

	if (res == 11)
	{
		n.x = 1;
		n.y = 0;
		n.z = 0;
	}
	if (res == 12)
	{
		n.x = 0;
		n.y = 1;
		n.z = 0;
	}
	if (res == 13)
	{
		n.x = 0;
		n.y = 0;
		n.z = 1;
	}
	return (n);
}

static t_vecteur	v_20(int res)
{
	t_vecteur n;

	if (res == 21)
	{
		n.x = 1;
		n.y = 0;
		n.z = 0;
	}
	if (res == 22)
	{
		n.x = 0;
		n.y = 0;
		n.z = 1;
	}
	if (res == 23)
	{
		n.x = 0;
		n.y = 1;
		n.z = 0;
	}
	return (n);
}

static t_vecteur	v_30(t_vecteur u)
{
	t_vecteur n;

	n.x = -u.z;
	n.y = 0;
	n.z = u.x;
	if (produit_scalaire(n, u) == 0)
		return (n);
	return (n);
}

t_vecteur			vecteur_normal(t_vecteur u)
{
	t_vecteur	n;
	int			res;

	init_vecteur(&n, 0, 0, 0);
	res = nb_0(u.x, u.y, u.z);
	if (res < 20)
		n = v_10(res);
	else if (res < 30)
		n = v_20(res);
	else if (res == 30)
		n = v_30(u);
	return (n);
}
