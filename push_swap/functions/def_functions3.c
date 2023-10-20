/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_functions3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:02:15 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 16:11:35 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ra_fnct(t_liste **pile_a, t_liste **pile_b)
{
	t_liste	*tmp;
	t_liste	*run;

	pile_b = NULL;
	if (lstsize(*pile_a) > 1)
	{
		tmp = (*pile_a);
		(*pile_a) = (*pile_a)->next;
		tmp->next = NULL;
		run = (*pile_a);
		while (run->next)
			run = run->next;
		run->next = tmp;
		tmp->previous = run;
	}
}

void	rb_fnct(t_liste **pile_a, t_liste **pile_b)
{
	t_liste	*tmp;
	t_liste	*run;	

	pile_a = NULL;
	if (lstsize(*pile_b) > 1)
	{
		tmp = (*pile_b);
		(*pile_b) = (*pile_b)->next;
		tmp->next = NULL;
		run = (*pile_b);
		while (run->next)
			run = run->next;
		run->next = tmp;
		tmp->previous = run;
	}
}

void	rr_fnct(t_liste **pile_a, t_liste **pile_b)
{
	ra_fnct(pile_a, pile_b);
	rb_fnct(pile_a, pile_b);
}

void	rra_fnct(t_liste **pile_a, t_liste **pile_b)
{
	t_liste	*tmp;
	t_liste	*run;	

	pile_b = NULL;
	if (lstsize(*pile_a) > 1)
	{
		tmp = *pile_a;
		run = (*pile_a);
		while (run->next)
			run = run->next;
		run->previous->next = NULL;
		run->next = tmp;
		run->previous = NULL;
		tmp->previous = run;
		(*pile_a) = run;
	}
}
