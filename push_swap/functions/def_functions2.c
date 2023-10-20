/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:02:11 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 07:10:06 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	sa_fnct(t_liste **pile_a, t_liste **pile_b)
{
	int	tmp;

	pile_b = NULL;
	if (lstsize(*pile_a) > 1)
	{
		tmp = (*pile_a)->nb;
		(*pile_a)->nb = (*pile_a)->next->nb;
		(*pile_a)->next->nb = tmp;
	}
}

void	sb_fnct(t_liste **pile_a, t_liste **pile_b)
{
	int	tmp;

	pile_a = NULL;
	if (lstsize(*pile_b) > 1)
	{
		tmp = (*pile_b)->nb;
		(*pile_b)->nb = (*pile_b)->next->nb;
		(*pile_b)->next->nb = tmp;
	}
}

void	ss_fnct(t_liste **pile_a, t_liste **pile_b)
{
	sa_fnct(pile_a, pile_b);
	sb_fnct(pile_a, pile_b);
}

void	pa_fnct(t_liste **pile_a, t_liste **pile_b)
{
	t_liste	*tmp;

	if (lstsize(*pile_b) != 0)
	{
		tmp = (*pile_b);
		(*pile_b) = (*pile_b)->next;
		add_front(pile_a, tmp);
	}
}

void	pb_fnct(t_liste **pile_a, t_liste **pile_b)
{
	t_liste	*tmp;

	if (lstsize(*pile_a) != 0)
	{
		tmp = (*pile_a);
		(*pile_a) = (*pile_a)->next;
		add_front(pile_b, tmp);
	}
}
