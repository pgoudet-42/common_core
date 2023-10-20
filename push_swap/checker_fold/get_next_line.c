/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:02:21 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 10:54:56 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;
	register int	i;
	register int	j;

	i = -1;
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res [i + j] = s2[j];
	res[i + j] = 0;
	free(s1);
	return (res);
}

int	get_next_line(char **line, int fd)
{
	register int	i;
	register int	res;
	char			buff[2];

	i = -1;
	res = read(fd, buff, 1);
	buff[1] = 0;
	if (res > 0 && buff[0] != 14 && buff[0] != EOF)
		*line = ft_strjoin(*line, buff);
	while (res > 0 && buff[0] != 14 && buff[0] != EOF)
	{
		res = read(fd, buff, 1);
		buff[1] = 0;
		if (res > 0 && buff[0] != 14 && buff[0] != EOF)
			*line = ft_strjoin(*line, buff);
	}
	if (res == 0)
		return (0);
	else if (res == -1)
		return (-1);
	else
		return (res);
}
