/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:33:06 by pgoudet           #+#    #+#             */
/*   Updated: 2021/02/13 16:28:44 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long int nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

void	ft_putstr(const char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	display(t_type *type)
{
	while (type->c[type->nb_cam].check[0] == '1')
		type->nb_cam++;
	if (!(type->id.img = malloc(sizeof(t_img) * type->nb_cam)))
		exit(0);
	type->id.mlx_ptr = mlx_init();
	if (type->args[0] == '-' && type->args[1] == '-' &&
	type->args[2] == 's' && type->args[3] == 'a' &&
	type->args[4] == 'v' && type->args[5] == 'e')
	{
		aff_sur_cam(type);
		enregistrement(*type);
	}
	else
	{
		type->id.wd_ptr = mlx_new_window(type->id.mlx_ptr,
		type->r.largeur, type->r.hauteur, "miniRT");
		mlx_key_hook(type->id.wd_ptr, gestion_window, (void *)type);
		mlx_hook(type->id.wd_ptr, 17, 1L << 17, exit_hook, (void *)type);
		mlx_loop(type->id.mlx_ptr);
	}
}

int		main(int argc, char **argv)
{
	t_type		type;
	char		**tab;
	int			i;

	if (argc > 3 || argc < 2)
	{
		ft_putstr("wrong number of args MOTHER FUCKER!");
		return (-1);
	}
	type.args = argv[1];
	type.args[ft_strlen(argv[1])] = 0;
	i = 0;
	type.nb_cam = 0;
	if ((tab = recup_el(argc, argv)) == NULL)
		return (-1);
	if (trait_tab(tab, &type) == -1)
		return (-1);
	while (tab[i])
		i++;
	init_type_values(&type, tab, i);
	display(&type);
	return (0);
}
