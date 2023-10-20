/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:25:35 by pgoudet           #+#    #+#             */
/*   Updated: 2021/02/13 15:39:42 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

int		count_nbs(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < (int)ft_strlen(str) && str[i])
	{
		while (i < (int)ft_strlen(str) && ft_isdigit(str[i]) == 0)
			i++;
		while (i < (int)ft_strlen(str) &&
		(ft_isdigit(str[i]) == 1 || str[i] == '.'))
			i++;
		res++;
		i++;
	}
	return (res);
}

int		check_filling(char **tab)
{
	int i;
	int id;
	int tab_ref[9];

	i = -1;
	tab_ref[0] = 2;
	tab_ref[1] = 4;
	tab_ref[2] = 7;
	tab_ref[3] = 7;
	tab_ref[5] = 9;
	tab_ref[4] = 7;
	tab_ref[6] = 10;
	tab_ref[7] = 11;
	tab_ref[8] = 12;
	while (tab[++i])
	{
		id = traitement_id(tab[i]) - is_single(tab[i]) - 1;
		if (count_nbs(tab[i]) != tab_ref[id])
		{
			write(1, tab[i], ft_strlen(tab[i]));
			write(1, "\n", 1);
			return (-1);
		}
	}
	return (0);
}

int		size_file(const char *file)
{
	int		fd;
	int		fin;
	int		read_res;
	char	*buff;
	char	*res;

	buff = malloc(10000);
	res = malloc(1);
	res[0] = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((read_res = read(fd, buff, 10000)) > 0)
		res = ft_strjoin(res, buff);
	close(fd);
	free(buff);
	fin = ft_strlen(res);
	free(res);
	return (fin);
}

char	*take_buff(int argc, char **argv)
{
	int		fd;
	int		buff_size;
	int		res;
	char	*buff;

	fd = -1;
	buff_size = -1;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		buff_size = size_file(argv[1]);
	}
	else
	{
		fd = open(argv[2], O_RDONLY);
		buff_size = size_file(argv[2]);
	}
	if (!(buff = malloc(buff_size + 1)) || fd < 1)
		return (0);
	if ((res = read(fd, buff, buff_size)) < 1)
		return (0);
	buff[res] = 0;
	close(fd);
	return (buff);
}
