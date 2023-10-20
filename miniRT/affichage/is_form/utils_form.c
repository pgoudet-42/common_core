/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:17:38 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 12:39:22 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../general.h"

t_point	inter_pl(t_droite d, t_pl *pl)
{
	double	part_bas;
	double	part_haute;
	double	t;
	t_point inter;

	part_bas = pl->eq.a * d.v.x + pl->eq.b * d.v.y + pl->eq.c * d.v.z;
	part_haute = -(pl->eq.a * d.p.x + pl->eq.b * d.p.y +
	pl->eq.c * d.p.z + pl->eq.d);
	inter.x = d.p.x + d.v.x;
	inter.y = d.p.y + d.v.y;
	inter.z = d.p.z + d.v.z;
	if (part_bas == 0)
	{
		if (check_eqpl(*pl, inter) == 1)
			return (inter);
		return (d.p);
	}
	t = part_haute / part_bas;
	if (t < 0)
		return (d.p);
	inter.x = d.v.x * t + d.p.x;
	inter.y = d.v.y * t + d.p.y;
	inter.z = d.v.z * t + d.p.z;
	return (inter);
}

void	max_min(double *max, double *min)
{
	double tmp;

	if (*max < *min)
	{
		tmp = *max;
		*max = *min;
		*min = tmp;
	}
}

int		is_inrange(t_point p1, t_cy cy)
{
	double	dist_ref;
	int		res;

	res = 0;
	dist_ref = distance_pt_pt(cy.p, cy.p_opp);
	if (distance_pt_pl(p1, cy.eq_p) < dist_ref
	&& distance_pt_pl(p1, cy.eq_p_opp) < dist_ref)
		return (1);
	return (0);
}
