/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:27:08 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/11 13:22:47 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

#define UP 1
#define DOWN 2

int	find_path(t_liste *liste, int pos)
{
	int		nb_act_up;
	int		nb_act_down;
	int		compt;
	int		size;
	t_liste	*run;

	run = liste;
	nb_act_down = 0;
	nb_act_up = 0;
	compt = 0;
	while (run->next && ++compt < pos)
		run = run->next;
	size = lstsize(liste);
	if (compt > size / 2)
		return (DOWN);
	else
		return (UP);
}

int	find_pos(t_liste *pile_a, int nb)
{
	int	pos;

	pos = 0;
	while (pile_a)
	{
		if (pile_a->nb == nb)
			return (pos);
		pos++;
		pile_a = pile_a->next;
	}
	pos = -1;
	return (pos);
}

int	wich_closer(t_liste *pile_a, int min, int max)
{
	int	nbr;
	int	good_nbr;
	int	pos;
	int	good_pos;

	good_nbr = INT_MAX;
	good_pos = -1;
	while (min < max)
	{
		pos = find_pos(pile_a, min);
		if (pos != -1)
		{
			if (find_path(pile_a, pos) == UP)
				nbr = pos;
			else
				nbr = lstsize(pile_a) - pos;
			if (nbr < good_nbr)
			{
				good_nbr = nbr;
				good_pos = pos;
			}
		}
		min++;
	}
	return (good_pos);
}

t_list	*sort_piles(t_liste **pile_a, t_liste **pile_b)
{
	int			max_pos;
	int			path;
	int			size;
	int			i;
	t_norm2		in;

	in.tmp = NULL;
	in.instruc = NULL;
	i = 0;
	size = lstsize(*pile_b);
	while (++i <= size)
	{
		max_pos = find_max(*pile_b);
		path = find_path(*pile_b, max_pos);
		in.tmp = back_on_top_b(pile_a, pile_b, max_pos, path);
		ft_lstadd_back(&in.instruc, in.tmp);
		pa_fnct(pile_a, pile_b);
		add_instruction(&in.instruc, &in.tmp, "pa");
	}
	return (in.instruc);
}
