/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5el.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:27:36 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 07:36:48 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_list	*go_on_top_a_bis(int pos, t_liste **pile_a, t_liste **pile_b)
{
	t_list	*tmp;
	t_list	*instruction;

	instruction = NULL;
	tmp = NULL;
	if (pos == 1)
	{
		sa_fnct(pile_a, pile_b);
		add_instruction(&instruction, &tmp, "sa");
	}
	else if (pos == 2)
	{
		ra_fnct(pile_a, pile_b);
		add_instruction(&instruction, &tmp, "ra");
		ra_fnct(pile_a, pile_b);
		add_instruction(&instruction, &tmp, "ra");
	}
	return (instruction);
}

t_list	*go_on_top_a(int pos, t_liste **pile_a, t_liste **pile_b)
{
	t_list	*tmp;
	t_list	*instruction;

	instruction = NULL;
	tmp = NULL;
	instruction = go_on_top_a_bis(pos, pile_a, pile_b);
	if (pos == 3)
	{
		rra_fnct(pile_a, pile_b);
		add_instruction(&instruction, &tmp, "rra");
		if (lstsize(*pile_a) > 4)
		{
			rra_fnct(pile_a, pile_b);
			add_instruction(&instruction, &tmp, "rra");
		}
	}
	else if (pos == 4)
	{
		rra_fnct(pile_a, pile_b);
		add_instruction(&instruction, &tmp, "rra");
	}
	return (instruction);
}

t_list	*go_on_top_b_bis(int pos, t_liste **pile_a, t_liste **pile_b)
{
	t_list	*tmp;
	t_list	*instruction;

	instruction = NULL;
	tmp = NULL;
	if (pos == 1)
	{
		sb_fnct(pile_a, pile_b);
		add_instruction(&instruction, &tmp, "sb");
	}
	else if (pos == 2)
	{
		rb_fnct(pile_a, pile_b);
		add_instruction(&instruction, &tmp, "rb");
		rb_fnct(pile_a, pile_b);
		add_instruction(&instruction, &tmp, "rb");
	}
	return (instruction);
}

t_list	*go_on_top_b(int pos, t_liste **pile_a, t_liste **pile_b)
{
	t_list	*tmp;
	t_list	*instruction;

	instruction = NULL;
	tmp = NULL;
	instruction = go_on_top_b_bis(pos, pile_a, pile_b);
	if (pos == 3)
	{
		rrb_fnct(pile_a, pile_b);
		add_instruction(&instruction, &tmp, "rrb");
		if (lstsize(*pile_b) > 4)
		{
			rrb_fnct(pile_a, pile_b);
			add_instruction(&instruction, &tmp, "rrb");
		}
	}
	else if (pos == 4)
	{
		rrb_fnct(pile_a, pile_b);
		add_instruction(&instruction, &tmp, "rrb");
	}
	return (instruction);
}
