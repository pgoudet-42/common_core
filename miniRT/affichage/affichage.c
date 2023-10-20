/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:31:38 by pgoudet           #+#    #+#             */
/*   Updated: 2021/02/16 14:00:50 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

void		creat_img(t_type *type)
{
	int i;
	int	j;

	i = -1;
	j = 0;
	while (type->c[++i].check[0] == '1')
	{
		type->id.img[i].img_ptr = mlx_new_image(type->id.mlx_ptr,
		type->r.largeur, type->r.hauteur);
		type->id.img[i].img_data = (int *)mlx_get_data_addr(
		type->id.img[i].img_ptr, &type->id.img[i].bpp,
		&type->id.img[i].size_line, &type->id.img[i].endian);
		type->id.img[i].check[0] = '1';
		type->id.img[i].check[1] = 0;
		while (j < (type->r.largeur * type->r.hauteur))
		{
			type->id.img[i].img_data[j] = 0;
			j++;
		}
	}
}

void		put_bit_in_pixel_in_img(t_type *type,
			int color, int index, int num_img)
{
	type->id.img[num_img].img_data[index] = color;
}

void		intersct(t_type *type, t_droite *ray_v,
					t_deplacement dep, int num_img)
{
	t_inter inter;
	int		index;

	index = 0;
	inter = is_qqch(type, *ray_v, 1000000000);
	if (inter.dist != -1)
	{
		inter.color = spot2(type, inter);
		inter.color.final = color_value(inter.color);
		index = dep.z * type->r.largeur + dep.x;
		put_bit_in_pixel_in_img(type, inter.color.final, index, num_img);
	}
}

static void	parcour_screen(t_deplacement dep, t_type *type, int i)
{
	t_droite	ray_visu;
	t_point		p;

	dep.x = -1;
	dep.z = -1;
	p = type->c[i].p1;
	init_cam(&type->c[i], type->r.largeur, type->r.hauteur);
	init_oeil(&ray_visu.p, type, i);
	while (++dep.z < type->r.hauteur)
	{
		p = p_fois_v(type->c[i].p1, type->c[i].v_ver,
		dep.z * type->c[i].raz);
		while (++dep.x < type->r.largeur)
		{
			p = p_fois_v(p, type->c[i].v_hor, type->c[i].rax * 1);
			ray_visu.v = vecteur(ray_visu.p, p);
			intersct(type, &ray_visu, dep, i);
		}
		p = type->c[i].p1;
		dep.x = -1;
	}
	dep.z = 1;
}

int			aff_sur_cam(t_type *type)
{
	t_deplacement	dep;
	int				i;

	i = -1;
	dep.x = 0;
	dep.z = 0;
	creat_img(type);
	while (type->c[++i].check[0] == '1')
		parcour_screen(dep, type, i);
	return (0);
}
