/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:13:15 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 08:24:56 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_list	*sort_2el(t_liste **pile_a, t_liste **pile_b)
{
	t_list	*instruc;

	instruc = NULL;
	if ((*pile_a)->next && (*pile_a)->next->nb < (*pile_a)->nb)
	{
		instruc = malloc(sizeof(t_list));
		instruc->content = "rra";
		rra_fnct(pile_a, pile_b);
	}
	return (instruc);
}

void	sort_3el_bis(
		t_liste **pile_a, t_liste **pile_b, t_list **instruc, t_list **tmp)
{
	pb_fnct(pile_a, pile_b);
	add_instruction(instruc, tmp, "pb");
	sa_fnct(pile_a, pile_b);
	add_instruction(instruc, tmp, "sa");
	pa_fnct(pile_a, pile_b);
	add_instruction(instruc, tmp, "pa");
}

t_list	*sort_3el(t_liste **pile_a, t_liste **pile_b)
{
	t_list	*instruc;
	t_list	*tmp;
	t_liste	*run;

	instruc = NULL;
	if ((*pile_a)->next->nb < (*pile_a)->nb)
	{
		add_instruction(&instruc, &tmp, "sa");
		sa_fnct(pile_a, pile_b);
	}
	run = lastel(*pile_a);
	if ((*pile_a)->nb > run->nb)
	{
		add_instruction(&instruc, &tmp, "rra");
		rra_fnct(pile_a, pile_b);
	}
	run = lastel(*pile_a);
	if ((*pile_a)->next->nb > run->nb)
		sort_3el_bis(pile_a, pile_b, &instruc, &tmp);
	return (instruc);
}

static	t_list	*sort_5el_bis(int *pos, t_liste **pile_a, t_liste **pile_b)
{
	t_list	*instruc;
	t_list	*tmp;
	int		size;

	instruc = NULL;
	tmp = NULL;
	size = lstsize(*pile_a);
	*pos = find_min(*pile_a);
	tmp = go_on_top_a(*pos, pile_a, pile_b);
	ft_lstadd_back(&instruc, tmp);
	pb_fnct(pile_a, pile_b);
	add_instruction(&instruc, &tmp, "pb");
	*pos = find_min(*pile_a);
	tmp = go_on_top_a(*pos, pile_a, pile_b);
	ft_lstadd_back(&instruc, tmp);
	pb_fnct(pile_a, pile_b);
	add_instruction(&instruc, &tmp, "pb");
	return (instruc);
}

t_list	*sort_5el(t_liste **pile_a, t_liste **pile_b)
{
	t_list	*instruc;
	t_list	*tmp;
	int		pos;
	int		size;

	tmp = NULL;
	size = lstsize(*pile_a);
	instruc = sort_5el_bis(&pos, pile_a, pile_b);
	if (size == 4)
	{
		tmp = sort_2el(pile_a, pile_b);
		ft_lstadd_back(&instruc, tmp);
	}
	else
	{
		tmp = sort_3el(pile_a, pile_b);
		ft_lstadd_back(&instruc, tmp);
	}
	pa_fnct(pile_a, pile_b);
	add_instruction(&instruc, &tmp, "pa");
	pa_fnct(pile_a, pile_b);
	add_instruction(&instruc, &tmp, "pa");
	return (instruc);
}
