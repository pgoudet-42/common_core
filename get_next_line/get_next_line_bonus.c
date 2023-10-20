/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:59:40 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/06 12:41:21 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <stdio.h>
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

int		retour(char *t, int ret)
{
	free(t);
	return (ret);
}

int		check_end_file(char **t, int r)
{
	if (pn(*t) >= ft_strlen(*t) && r == 0)
	{
		free(*t);
		*t = NULL;
		return (0);
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char *t[4096];
	int			r;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	r = 5;
	if (!t[fd])
		t[fd] = buffs_to_str(fd, buff, &r);
	if (r == -1)
		return (retour(t[fd], -1));
	while ((pn(t[fd]) == ft_strlen(t[fd])) &&
	(r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[BUFFER_SIZE] = 0;
		if (r < BUFFER_SIZE)
			buff[r] = 0;
		t[fd] = ft_strjoin(t[fd], buff);
	}
	*line = malloc(pn(t[fd]) + 1);
	ft_memcpy(*line, t[fd], pn(t[fd]));
	if ((r = check_end_file(&t[fd], r)) != -1)
		return (r);
	t[fd] = ft_substr(t[fd], pn(t[fd]) + 1, ft_strlen(t[fd]) - pn(t[fd]));
	return (1);
}
