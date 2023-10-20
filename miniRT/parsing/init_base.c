/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 13:23:48 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/28 15:11:34 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

void	init_l_val(char *tab, t_type *type)
{
	int			i;
	static int	j;

	i = 0;
	type->l[j].p.x = ft_atoi(tab, &i);
	type->l[j].p.y = ft_atoi(tab, &i);
	type->l[j].p.z = ft_atoi(tab, &i);
	type->l[j].ra_lum = ft_atoi(tab, &i);
	type->l[j].color.o = 0;
	type->l[j].color.r = ft_atoi(tab, &i);
	type->l[j].color.g = ft_atoi(tab, &i);
	type->l[j].color.b = ft_atoi(tab, &i);
	type->l[j].color.final = color_value(type->l[j].color);
	type->l[j].check[0] = '1';
	type->l[j].check[1] = 0;
	j++;
}

void	init_c_val(char *tab, t_type *type)
{
	int			i;
	static int	j;

	i = 0;
	type->c[j].p1.x = ft_atoi(tab, &i);
	type->c[j].p1.y = ft_atoi(tab, &i);
	type->c[j].p1.z = ft_atoi(tab, &i);
	type->c[j].v.x = ft_atoi(tab, &i);
	type->c[j].v.y = ft_atoi(tab, &i);
	type->c[j].v.z = ft_atoi(tab, &i);
	type->c[j].fov = ft_atoi(tab, &i);
	type->c[j].check[0] = '1';
	type->c[j].check[1] = '\0';
	j++;
}

void	init_a_val(char *tab, t_type *type)
{
	int			i;
	static int	j;

	i = 0;
	type->a.ra = ft_atoi(tab, &i);
	type->a.color.o = 0;
	type->a.color.r = ft_atoi(tab, &i);
	type->a.color.g = ft_atoi(tab, &i);
	type->a.color.b = ft_atoi(tab, &i);
	j++;
}

void	init_r_val(char *tab, t_type *type)
{
	int			i;

	i = 0;
	type->r.largeur = (int)ft_atoi(tab, &i);
	type->r.hauteur = (int)ft_atoi(tab, &i);
	if (type->r.largeur > 2560)
		type->r.largeur = 2560;
	if (type->r.hauteur > 1400)
		type->r.hauteur = 1400;
}
