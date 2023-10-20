/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:20:50 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/21 16:13:35 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_init(int siz, int fd, char *b, t_buf *buff)
{
	(void)b;
	if (buff->size == 0 || fd != buff->fd)
	{
		buff->fd = fd;
		buff->len = siz;
		buff->size = siz;
		buff->end = 0;
		buff->pos = 0;
		buff->last = 0;
		buff->add = 0;
		buff->flag = 0;
	}
	if (buff->fd == 0 && buff->len != buff->size && !buff->flag)
	{
		buff->len = siz;
		buff->end = 0;
		buff->pos = 0;
		buff->last = 0;
	}
	buff->line = NULL;
	buff->ligne = malloc(1);
	if (buff->ligne == NULL)
		return (-1);
	buff->ligne[0] = 0;
	return (0);
}

size_t	gnl_read_bytes(t_buf *pb, char *buffer)
{
	size_t		n;
	int			f1;
	int			f2;

	f1 = 0;
	f2 = 0;
	while (!f1)
	{
		n = read(pb->fd, buffer, BUFFER_SIZE);
		if (n == BUFFER_SIZE || (n > 0 && buffer[n - 1] == '\n')
			|| (n == 0 && f2 == 0))
			f1 = 1;
		else
			write(1, "  \b\b**", 4);
		f2++;
	}
	if ((int)n < pb->size)
	{
		pb->len = n;
		pb->end = 1;
	}
	pb->last = 0;
	pb->pos = 0;
	return (n);
}

int	get_next(t_buf *pb, char *buffer)
{
	int		n;

	while (1)
	{
		if (pb->pos == 0 && !pb->end)
		{
			n = gnl_read_bytes(pb, buffer);
			if (n == -1)
				return (-1);
		}
		if (pb->pos == pb->len)
			return (0);
		if (buffer[pb->pos] == '\n')
		{
			if (pb->fd == 0 && (pb->pos + 1) != pb->len)
				pb->flag = 1;
			return (1);
		}
		pb->pos++;
	}
}

int	get_next_line1(int fd, char *buffer, t_buf *tb)
{
	int				f;

	f = gnl_init(BUFFER_SIZE, fd, buffer, tb);
	if (f == -1)
		return (f);
	while (!f && !(tb->end && tb->pos >= tb->len))
	{
		f = get_next(tb, buffer);
		if (f == -1)
			return (-1);
		if (!gnl_add_new(tb))
			return (-1);
		if (f == 1)
		{
			tb->pos++;
			tb->last = tb->pos;
		}
		if (f == 0 && !tb->end)
			tb->pos = 0;
	}
	return (f);
}

int	get_next_line(int fd, char **li)
{
	static t_buf	buft[16];
	int				f;
	t_buf			*buf;

	buf = &(buft[0]);
	f = get_next_line1(fd, buf->buf, buf);
	if (f == 0)
		buf->fd = -1;
	if (f >= 0)
		*li = buf->ligne;
	gnl_free(&buf->line);
	return (f);
}
