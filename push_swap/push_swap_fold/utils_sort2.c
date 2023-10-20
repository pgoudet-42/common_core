/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:12:54 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/11 13:23:18 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

#define UP 1
#define DOWN 2

static t_list	*back_on_top_a_bis(
		int pos, t_liste **pile_a, t_liste **pile_b, int way)
{
	t_list	*instruc;
	t_list	*tmp;
	int		repete;

	tmp = NULL;
	instruc = NULL;
	if (pos == 1)
	{
		sa_fnct(pile_a, pile_b);
		add_instruction(&instruc, &tmp, "sa");
	}
	else if (way == DOWN)
	{
		repete = lstsize(*pile_a) - pos;
		way = -1;
		while (++way < repete)
		{
			rra_fnct(pile_a, pile_b);
			add_instruction(&instruc, &tmp, "rra");
		}
	}
	return (instruc);
}

t_list	*back_on_top_a(t_liste **pile_a, t_liste **pile_b, int pos, int way)
{
	t_list	*instruc;
	t_list	*tmp;
	int		repete;

	tmp = NULL;
	instruc = NULL;
	if (pos == 1 || way == DOWN)
	{
		instruc = back_on_top_a_bis(pos, pile_a, pile_b, way);
	}
	else
	{
		repete = pos;
		way = -1;
		while (++way < repete)
		{
			ra_fnct(pile_a, pile_b);
			add_instruction(&instruc, &tmp, "ra");
		}
	}
	return (instruc);
}

static t_list	*back_on_top_b_bis(
		int pos, t_liste **pile_a, t_liste **pile_b, int way)
{
	t_list	*instruc;
	t_list	*tmp;
	int		repete;

	tmp = NULL;
	instruc = NULL;
	if (pos == 1)
	{
		sb_fnct(pile_a, pile_b);
		add_instruction(&instruc, &tmp, "sb");
	}
	else if (way == DOWN)
	{
		repete = lstsize(*pile_b) - pos;
		way = -1;
		while (++way < repete)
		{
			rrb_fnct(pile_a, pile_b);
			add_instruction(&instruc, &tmp, "rrb");
		}
	}
	return (instruc);
}

t_list	*back_on_top_b(t_liste **pile_a, t_liste **pile_b, int pos, int way)
{
	t_list	*instruc;
	t_list	*tmp;
	int		repete;

	tmp = NULL;
	instruc = NULL;
	if (pos == 1 || way == DOWN)
	{
		instruc = back_on_top_b_bis(pos, pile_a, pile_b, way);
	}
	else
	{
		repete = pos;
		way = -1;
		while (++way < repete)
		{
			rb_fnct(pile_a, pile_b);
			add_instruction(&instruc, &tmp, "rb");
		}
	}
	return (instruc);
}
