/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_functions4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:02:18 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 08:27:02 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rrb_fnct(t_liste **pile_a, t_liste **pile_b)
{
	t_liste	*tmp;
	t_liste	*run;

	pile_a = NULL;
	if (lstsize(*pile_b) > 1)
	{
		tmp = *pile_b;
		run = (*pile_b);
		while (run->next)
			run = run->next;
		run->previous->next = NULL;
		run->next = tmp;
		run->previous = NULL;
		tmp->previous = run;
		(*pile_b) = run;
	}
}

void	rrr_fnct(t_liste **pile_a, t_liste **pile_b)
{
	rra_fnct(pile_a, pile_b);
	rrb_fnct(pile_a, pile_b);
}
