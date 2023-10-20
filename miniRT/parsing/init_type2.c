/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_type2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:15:01 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/26 12:54:19 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

void	init_last_structs(t_nbtype nbtype, t_type *type)
{
	type->sp[nbtype.sp.value].check[0] = 0;
	type->tr[nbtype.tr.value].check[0] = 0;
	type->sq[nbtype.sq.value].check[0] = 0;
	type->pl[nbtype.pl.value].check[0] = 0;
	type->cy[nbtype.cy.value].check[0] = 0;
	type->c[nbtype.c.value].check[0] = 0;
	type->l[nbtype.l.value].check[0] = 0;
	type->sp[nbtype.sp.value].check[1] = 0;
	type->tr[nbtype.tr.value].check[1] = 0;
	type->sq[nbtype.sq.value].check[1] = 0;
	type->pl[nbtype.pl.value].check[1] = 0;
	type->cy[nbtype.cy.value].check[1] = 0;
	type->c[nbtype.c.value].check[1] = 0;
	type->l[nbtype.l.value].check[1] = 0;
}
