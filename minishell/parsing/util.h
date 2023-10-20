/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:56:41 by pgoudet           #+#    #+#             */
/*   Updated: 2021/03/15 07:02:48 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

typedef struct s_compt
{
	int	i;
	int	j;
	int	k;
}				t_compt;

typedef struct s_compt2
{
	int		x;
	int		y;
	int		flag;
}				t_compt2;

void			del_el(int i, int j);
void			del_com(int i);
char			**tab_dup(char **tab);
void			else_rmarg(int i, int j, int x);
#endif
