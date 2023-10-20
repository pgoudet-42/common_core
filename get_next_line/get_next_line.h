/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:49:53 by pgoudet           #+#    #+#             */
/*   Updated: 2020/12/06 12:41:33 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

typedef struct	s_buff
{
	char			*buff;
	struct s_buff	*next;
}				t_buff;
int				get_next_line(int fd, char **line);
int				ft_strlen(char *str);
void			*ft_memcpy(void *dest, const void *src, int n);
void			ft_copy(int size, char **strs, char *sep, char *res);
char			*ft_substr(char *s, int start, int len);
char			*ft_strjoin(char *s1, char *s2);
char			*buffs_to_str(int fd, char *buff, int *r);
int				pn(char *tab);
int				retour(char *tab, int ret);
int				check_end_file(char **tab, int r);

#endif
