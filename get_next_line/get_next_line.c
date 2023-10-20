/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:37:44 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/07 09:56:09 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*buffs_to_str(int fd, char *buff, int *r)
{
	char	*tab2;

	*r = read(fd, buff, BUFFER_SIZE);
	if (*r == -1)
		return (0);
	buff[*r] = 0;
	tab2 = malloc(ft_strlen(buff) + 1);
	if (!tab2)
		return (0);
	ft_memcpy(tab2, buff, (size_t)*r);
	tab2[*r] = 0;
	return (tab2);
}

int		retour(char *tab, int ret)
{
	free(tab);
	return (ret);
}

int		check_end_file(char **tab, int r)
{
	if (pn(*tab) >= ft_strlen(*tab) && r == 0)
	{
		free(*tab);
		*tab = NULL;
		return (0);
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char *tab = NULL;
	int			r;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	r = 5;
	if (!tab)
		tab = buffs_to_str(fd, buff, &r);
	if (r == -1)
		return (retour(tab, -1));
	while ((pn(tab) == ft_strlen(tab)) && (r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = 0;
		tab = ft_strjoin(tab, buff);
	}
	*line = malloc(pn(tab) + 1);
	ft_memcpy(*line, tab, pn(tab));
	if ((r = check_end_file(&tab, r)) != -1)
		return (r);
	tab = ft_substr(tab, pn(tab) + 1, ft_strlen(tab) - pn(tab));
	return (1);
}
