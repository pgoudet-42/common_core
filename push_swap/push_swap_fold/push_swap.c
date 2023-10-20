/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 12:05:24 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 08:19:32 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	find_position2(t_liste *pile, int data, int pos)
{
	int	i;
	int	compt;

	i = 0;
	compt = 0;
	while (pile)
	{
		if (pile->nb < data && compt != pos)
			i++;
		else if (pile->nb == data && compt < pos)
			i++;
		compt++;
		pile = pile->next;
	}
	return (i);
}

t_liste	*find_position(t_liste *pile)
{
	t_liste	*tmp;
	t_liste	*tmp2;
	t_liste	*first;
	int		pos;

	tmp = NULL;
	pos = 0;
	first = pile;
	while (pile)
	{
		tmp2 = malloc (sizeof(t_liste));
		tmp2->nb = find_position2(first, pile->nb, pos);
		add_back(&tmp, tmp2);
		pile = pile->next;
		pos++;
	}
	return (tmp);
}

int	main(int argc, char **argv)
{
	t_liste	*pat;
	t_liste	*pbt;
	t_liste	*pile_a;
	t_liste	*pile_b;
	t_list	*instruc;

	if (check_argv(argv, argc) == -1)
		error_exit("main");
	pile_a = arg_to_int(argv, argc);
	pile_b = NULL;
	pat = find_position(pile_a);
	pbt = find_position(pile_b);
	if (validate(pat) == 0)
		return (0);
	else if (lstsize(pile_a) <= 2)
		instruc = sort_2el(&pat, &pbt);
	else if (lstsize(pile_a) == 3)
		instruc = sort_3el(&pat, &pbt);
	else if (lstsize(pile_a) <= 5)
		instruc = sort_5el(&pat, &pbt);
	else
		instruc = sort(&pat, &pbt);
	display_list(instruc);
	return (0);
}
