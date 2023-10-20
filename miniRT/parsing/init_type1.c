/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_type1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 13:12:44 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/26 12:53:52 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

void	init_sq_val(char *tab, t_type *type)
{
	int			i;
	static int	j;

	i = 0;
	type->sq[j].p.x = ft_atoi(tab, &i);
	type->sq[j].p.y = ft_atoi(tab, &i);
	type->sq[j].p.z = ft_atoi(tab, &i);
	type->sq[j].v.x = ft_atoi(tab, &i);
	type->sq[j].v.y = ft_atoi(tab, &i);
	type->sq[j].v.z = ft_atoi(tab, &i);
	type->sq[j].hauteur = ft_atoi(tab, &i);
	type->sq[j].color.o = 0;
	type->sq[j].color.r = ft_atoi(tab, &i);
	type->sq[j].color.g = ft_atoi(tab, &i);
	type->sq[j].color.b = ft_atoi(tab, &i);
	type->sq[j].check[0] = '1';
	type->sq[j].check[1] = '\0';
	j++;
}

void	init_tr_val(char *tab, t_type *type)
{
	int			i;
	static int	j;

	i = 0;
	type->tr[j].p1.x = ft_atoi(tab, &i);
	type->tr[j].p1.y = ft_atoi(tab, &i);
	type->tr[j].p1.z = ft_atoi(tab, &i);
	type->tr[j].p2.x = ft_atoi(tab, &i);
	type->tr[j].p2.y = ft_atoi(tab, &i);
	type->tr[j].p2.z = ft_atoi(tab, &i);
	type->tr[j].p3.x = ft_atoi(tab, &i);
	type->tr[j].p3.y = ft_atoi(tab, &i);
	type->tr[j].p3.z = ft_atoi(tab, &i);
	type->tr[j].color.o = 0;
	type->tr[j].color.r = ft_atoi(tab, &i);
	type->tr[j].color.g = ft_atoi(tab, &i);
	type->tr[j].color.b = ft_atoi(tab, &i);
	type->tr[j].check[0] = '1';
	type->tr[j].check[1] = '\0';
	j++;
}

void	init_sp_val(char *tab, t_type *type)
{
	int			i;
	static int	j;

	i = 0;
	type->sp[j].p.x = ft_atoi(tab, &i);
	type->sp[j].p.y = ft_atoi(tab, &i);
	type->sp[j].p.z = ft_atoi(tab, &i);
	type->sp[j].diam = ft_atoi(tab, &i);
	type->sp[j].color.o = 0;
	type->sp[j].color.r = ft_atoi(tab, &i);
	type->sp[j].color.g = ft_atoi(tab, &i);
	type->sp[j].color.b = ft_atoi(tab, &i);
	type->sp[j].check[0] = '1';
	type->sp[j].check[1] = '\0';
	j++;
}

void	init_cy_val(char *tab, t_type *type)
{
	int			i;
	static int	j;

	i = 0;
	type->cy[j].p.x = ft_atoi(tab, &i);
	type->cy[j].p.y = ft_atoi(tab, &i);
	type->cy[j].p.z = ft_atoi(tab, &i);
	type->cy[j].v_or.x = ft_atoi(tab, &i);
	type->cy[j].v_or.y = ft_atoi(tab, &i);
	type->cy[j].v_or.z = ft_atoi(tab, &i);
	type->cy[j].diam = ft_atoi(tab, &i);
	type->cy[j].haut = ft_atoi(tab, &i);
	type->cy[j].color.o = 0;
	type->cy[j].color.r = ft_atoi(tab, &i);
	type->cy[j].color.g = ft_atoi(tab, &i);
	type->cy[j].color.b = ft_atoi(tab, &i);
	type->cy[j].check[0] = '1';
	type->cy[j].check[1] = '\0';
	j++;
}

void	init_pl_val(char *tab, t_type *type)
{
	int			i;
	static int	j;

	i = 0;
	type->pl[j].p.x = ft_atoi(tab, &i);
	type->pl[j].p.y = ft_atoi(tab, &i);
	type->pl[j].p.z = ft_atoi(tab, &i);
	type->pl[j].v_or.x = ft_atoi(tab, &i);
	type->pl[j].v_or.y = ft_atoi(tab, &i);
	type->pl[j].v_or.z = ft_atoi(tab, &i);
	type->pl[j].color.o = 0;
	type->pl[j].color.r = ft_atoi(tab, &i);
	type->pl[j].color.g = ft_atoi(tab, &i);
	type->pl[j].color.b = ft_atoi(tab, &i);
	type->pl[j].check[0] = '1';
	type->pl[j].check[1] = '\0';
	j++;
}
