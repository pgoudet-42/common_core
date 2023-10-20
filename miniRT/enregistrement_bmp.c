/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enregistrement_bmp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 07:07:39 by pgoudet           #+#    #+#             */
/*   Updated: 2021/02/16 14:00:13 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include <fcntl.h>

void	write_fd(int fd, t_type type)
{
	int taille;
	int null;

	null = 00;
	write(fd, "BM", 2);
	taille = (type.r.hauteur * type.r.largeur * 4) + 54;
	write(fd, &taille, 4);
	write(fd, &null, 4);
	taille = 54;
	write(fd, &taille, 4);
	taille = 40;
	write(fd, &taille, 4);
	write(fd, &type.r.largeur, 4);
	write(fd, &type.r.hauteur, 4);
	taille = 1;
	write(fd, &taille, 2);
	taille = 32;
	write(fd, &taille, 2);
	write(fd, &null, 4);
	write(fd, &null, 4);
	write(fd, &null, 4);
	write(fd, &null, 4);
	write(fd, &null, 4);
	write(fd, &null, 4);
}

int		enregistrement(t_type type)
{
	int				fd;
	int				x;
	int				z;
	unsigned int	tmp;

	fd = open("capture.bmp", O_CREAT | O_WRONLY, S_IRWXU);
	if (fd == -1)
		return (-1);
	write_fd(fd, type);
	x = -1;
	z = type.r.hauteur;
	while (--z >= 0)
	{
		while (++x < type.r.largeur)
		{
			tmp = (unsigned)type.id.img[0].img_data[((type.r.largeur * z)) + x];
			write(fd, &tmp, 4);
		}
		x = -1;
	}
	return (0);
}
