/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lum1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:19:19 by pgoudet           #+#    #+#             */
/*   Updated: 2021/02/03 09:16:46 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.h"

int				is_same_side(t_eqplan eq, t_droite d1, t_point p_lum)
{
	double sign;
	double sign2;

	sign = (eq.a * d1.p.x) + (eq.b * d1.p.y) + (eq.c * d1.p.z) + eq.d;
	sign2 = (eq.a * p_lum.x) + (eq.b * p_lum.y) + (eq.c * p_lum.z) + eq.d;
	if (sign <= 0 && sign2 <= 0)
		return (1);
	if (sign >= 0 && sign2 >= 0)
		return (1);
	return (0);
}

static t_color	init(t_type *type, t_inter inter, t_color **lum_tab)
{
	t_color ambiante;
	t_color base;
	int		compt;

	compt = 0;
	while (type->l[compt].check[0] == '1')
		compt++;
	*lum_tab = malloc(sizeof(t_color) * compt);
	init_color(&base, 0, 0, 0);
	base = inter.color;
	init_color(&ambiante, type->a.color.r * type->a.ra,
	type->a.color.g * type->a.ra, type->a.color.b * type->a.ra);
	base = addition_color(base, ambiante);
	return (base);
}

static void		end(t_color *base, t_color *lum_tab, int k)
{
	if (k > -1)
		*base = addition_color(*base, color_max(lum_tab, k));
	if (k < 0)
		init_color(base, 0, 0, 0);
}

static double	ps(t_inter inter, t_droite ray_lum)
{
	t_vecteur	oi;
	double		res;

	res = 0;
	oi = v_from_eq(inter.eq);
	normalisation_vecteurs(&oi);
	normalisation_vecteurs(&ray_lum.v);
	res = produit_scalaire(ray_lum.v, oi);
	if (res <= 0)
		res = 0;
	return (res);
}

t_color			spot2(t_type *type, t_inter inter)
{
	int			i;
	int			k;
	t_droite	ray_lum;
	t_color		*lum_tab;
	t_color		base;

	k = -1;
	i = -1;
	lum_tab = NULL;
	base = init(type, inter, &lum_tab);
	while (type->l[++i].check[0] == '1')
	{
		ray_lum = ray(inter, vecteur(inter.p, type->l[i].p));
		if (is_qqch(type, ray_lum, distance_pt_pt(inter.p,
		type->l[i].p)).check[0] != '1')
		{
			if (is_same_side(inter.eq, inter.d_ray, type->l[i].p) == 1)
				lum_tab[++k] = lum_pond(type->l[i].color, ps(inter, ray_lum));
		}
	}
	end(&base, lum_tab, k);
	free(lum_tab);
	return (base);
}
