/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lum2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:20:18 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 15:02:07 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.h"

t_droite	ray(t_inter inter, t_vecteur v)
{
	t_droite d;

	d.v.x = v.x;
	d.v.y = v.y;
	d.v.z = v.z;
	d.p.x = inter.p.x + 1 * (d.v.x / taille_vecteur(d.v));
	d.p.y = inter.p.y + 1 * (d.v.y / taille_vecteur(d.v));
	d.p.z = inter.p.z + 1 * (d.v.z / taille_vecteur(d.v));
	return (d);
}

t_color		couleur_moyenne(t_color *color_tab,
			double res_ps, double side, int len)
{
	int			i;
	t_color		couleur_moy;

	i = -1;
	couleur_moy.r = 0;
	couleur_moy.g = 0;
	couleur_moy.b = 0;
	while (++i < len)
	{
		if (i == 0)
			init_color(&couleur_moy, color_tab[i].r * side,
			color_tab[i].g * side, color_tab[i].b * side);
		else
		{
			couleur_moy.r += color_tab[i].r * res_ps;
			couleur_moy.g += color_tab[i].g * res_ps;
			couleur_moy.b += color_tab[i].b * res_ps;
		}
	}
	couleur_moy.r = (couleur_moy.r / len);
	couleur_moy.g = (couleur_moy.g / len);
	couleur_moy.b = (couleur_moy.b / len);
	return (couleur_moy);
}

t_color		addition_color(t_color c1, t_color c2)
{
	t_color res;

	res.r = c1.r + c2.r;
	res.g = c1.g + c2.g;
	res.b = c1.b + c2.b;
	res.r = res.r / 2;
	res.g = res.g / 2;
	res.b = res.b / 2;
	return (res);
}

t_color		color_max(t_color *lum_tab, int len)
{
	int		i;
	int		max;
	t_color	cres;

	i = -1;
	cres.r = 0;
	cres.g = 0;
	cres.b = 0;
	cres.final = color_value(cres);
	max = 0;
	while (++i <= len)
	{
		if (lum_tab[i].r > cres.r)
			cres.r = lum_tab[i].r;
		if (lum_tab[i].g > cres.g)
			cres.g = lum_tab[i].g;
		if (lum_tab[i].b > cres.b)
			cres.b = lum_tab[i].b;
	}
	return (cres);
}

t_color		lum_pond(t_color color, double res_ps)
{
	color.r = color.r * res_ps;
	color.g = color.g * res_ps;
	color.b = color.b * res_ps;
	return (color);
}
