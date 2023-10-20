/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 06:37:30 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 16:24:42 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	add_instruction(t_list **instruc, t_list **tmp, char *instruction)
{
	*tmp = malloc(sizeof(t_list));
	(*tmp)->content = instruction;
	(*tmp)->next = NULL;
	ft_lstadd_back(instruc, *tmp);
}

void	display_list(t_list *list)
{
	while (list)
	{
		write(1, list->content, ft_strlen(list->content));
		write(1, "\n", 1);
		list = list->next;
	}
}

int	find_offset(int size, int *min, int *max)
{
	int	offset;

	if (size == 500)
	{
		*min = 0;
		*max = 59;
		offset = 63;
	}
	else if (size == 100)
	{
		*min = 0;
		*max = 20;
		offset = 20;
	}
	else
	{
		*min = 0;
		offset = size / (6 + 1);
		*max = size - (6 * offset);
	}
	return (offset);
}

static	t_list	*sort_bis(t_liste **pile_a, t_liste **pile_b, t_norm norm)
{
	t_list	*instruc;
	t_list	*tmp;

	instruc = NULL;
	tmp = NULL;
	while (++norm.i < (norm.max - norm.min))
	{
		norm.pos = wich_closer(*pile_a, norm.min, norm.max);
		if (norm.pos != -1)
		{
			tmp = back_on_top_a(pile_a, pile_b, norm.pos, \
			find_path(*pile_a, norm.pos));
			ft_lstadd_back(&instruc, tmp);
			pb_fnct(pile_a, pile_b);
			add_instruction(&instruc, &tmp, "pb");
		}
	}
	return (instruc);
}

t_list	*sort(t_liste **pile_a, t_liste **pile_b)
{
	t_list	*instruc;
	t_list	*tmp;
	t_norm	norm;

	instruc = NULL;
	tmp = NULL;
	norm.size = lstsize(*pile_a);
	norm.offset = find_offset(norm.size, &norm.min, &norm.max);
	if (norm.offset == 0)
		norm.offset++;
	while (norm.max <= norm.size)
	{
		norm.i = -1;
		tmp = sort_bis(pile_a, pile_b, norm);
		ft_lstadd_back(&instruc, tmp);
		norm.max += norm.offset;
		norm.min += norm.offset;
	}
	tmp = sort_piles(pile_a, pile_b);
	ft_lstadd_back(&instruc, tmp);
	return (instruc);
}
