/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_fenetre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:40:28 by pgoudet           #+#    #+#             */
/*   Updated: 2021/02/08 09:14:24 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	go_screen(t_type *type)
{
	aff_sur_cam(type);
	mlx_put_image_to_window(type->id.mlx_ptr, type->id.wd_ptr,
	type->id.img[0].img_ptr, 0, 0);
	write(1, "________END_OF_CHARGEMENT_______\n", 34);
}

int		exit_hook2(t_type *type, int flag)
{
	int i;

	i = -1;
	while (type->c[++i].check[0] == '1' && flag == 1)
		mlx_destroy_image(type->id.mlx_ptr, type->id.img[i].img_ptr);
	mlx_destroy_window(type->id.mlx_ptr, type->id.wd_ptr);
	ft_putstr("bye bye!");
	exit(0);
}

int		gestion_window(int key, t_type *type)
{
	static int i;
	static int flag;

	if (key == 53)
		exit_hook2(type, flag);
	else if (key == 124)
	{
		if (++i >= type->nb_cam)
			i = 0;
		mlx_put_image_to_window(type->id.mlx_ptr, type->id.wd_ptr,
		type->id.img[i].img_ptr, 0, 0);
	}
	else if (key == 123)
	{
		if (--i < 0)
			i = type->nb_cam - 1;
		mlx_put_image_to_window(type->id.mlx_ptr, type->id.wd_ptr,
		type->id.img[i].img_ptr, 0, 0);
	}
	else if (key == 36)
	{
		flag = 1;
		go_screen(type);
	}
	return (0);
}

int		exit_hook(t_type *type)
{
	int i;

	i = -1;
	while (type->id.img[++i].check[0] == '1')
		mlx_destroy_image(type->id.mlx_ptr, type->id.img[i].img_ptr);
	mlx_destroy_window(type->id.mlx_ptr, type->id.wd_ptr);
	ft_putstr("bye bye!");
	exit(0);
}
