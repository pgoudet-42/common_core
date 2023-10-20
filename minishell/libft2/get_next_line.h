/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drochaix <drochaix@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:25:51 by drochaix          #+#    #+#             */
/*   Updated: 2021/03/16 15:16:26 by drochaix         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BUFFER_SIZE 2048

typedef struct s_line
{
	int				size;
	int				len;
	char			*buf;
	struct s_line	*next;
}				t_line;
typedef struct s_buf
{
	int		fd;
	int		size;
	int		len;
	int		pos;
	int		last;
	int		end;
	int		add;
	int		flag;
	char	buf[BUFFER_SIZE];
	char	*ligne;
	t_line	*line;
}				t_buf;
int				get_next_line(int fd, char **line);
char			*gnl_rest(t_line *lst, int vide);
int				gnl_add(t_line **b, t_buf *tb, char *p);
void			gnl_free(t_line **b);
int				gnl_add_new(t_buf *tb);
char			*gnl_rest_new(t_buf *pb, int vide);
#endif
