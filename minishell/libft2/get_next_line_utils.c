/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:22:00 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/16 14:07:22 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_free(t_line **b)
{
	t_line	*pl;
	t_line	*pl1;

	pl = *b;
	if (pl == NULL)
		return ;
	while (pl)
	{
		if (pl->buf)
		{
			free(pl->buf);
		}
		pl1 = pl;
		pl = pl->next;
		free(pl1);
	}
	*b = NULL;
}

int	gnl_copy(char *old, char *new)
{
	int		i;

	i = 0;
	while (old[i])
	{
		new[i] = old[i];
		i++;
	}
	return (i);
}

int	gnl_add_new(t_buf *tb)
{
	int		l;
	int		i;
	int		j;
	char	*old;
	char	*new;

	l = tb->pos - tb->last;
	if (l == 0)
		return (1);
	old = tb->ligne;
	i = 0;
	while (old[i++])
		l++;
	new = malloc(l + 1);
	if (new == NULL)
		return (0);
	i = gnl_copy(old, new);
	j = tb->last;
	while (i < l)
		new[i++] = tb->buf[j++];
	new[i] = 0;
	free(tb->ligne);
	tb->ligne = new;
	return (1);
}

void	sigintHandlergnl(int sig_num)
{
	(void)sig_num;
	if (write(STDOUT_FILENO, " \b\b  \b\b", 8) < 0)
		return ;
	signal(SIGINT, sigintHandlergnl);
	exit(0);
}
