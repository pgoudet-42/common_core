/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:41:24 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/11 12:35:58 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../checker.h"

int	nbrlen(int nbr)
{
	int	i;

	i = 1;
	while (nbr / 10 > 0)
	{
		nbr =nbr / 10;
		i++;
	}
	return (i);
}

int	is_sorted(t_liste *a)
{
	int	max;
	int	max2;
	int	i;

	max = INT_MIN;
	i = -1;
	while (a->next)
	{
		i++;
		if (max <= a->nb)
		{
			max = a->nb;
			max2 = i;
		}
		a = a->next;
	}
	if (max2 < lstsize(a))
		return (0);
	return (1);
}

static void	while_display_stacks(t_liste *a, t_liste *b, int size_nbr)
{
	int	k;

	k = -1;
	while (a || b)
	{
		if (a)
		{
			ft_putnbr_fd(a->nb, 1);
			a = a->next;
		}
		else
			write (1, " ", 1);
		while (++k < size_nbr)
			write(1, " ", 1);
		if (b)
		{
			ft_putnbr_fd(b->nb, 1);
			b = b->next;
		}
		write(1, "\n", 1);
		k = -1;
	}
}

void	display_stacks(t_liste *a, t_liste *b)
{
	int	i;
	int	j;
	int	k;
	int	size_nbr;

	i = -1;
	j = -1;
	k = -1;
	size_nbr = nbrlen(max(a));
	while_display_stacks(a, b, size_nbr);
	write (1, "_", 1);
	while (++k < size_nbr)
		write(1, " ", 1);
	write (1, "_\n", 2);
	write(1, "a", 1);
	k = -1;
	while (++k < size_nbr)
		write(1, " ", 1);
	write(1, "b\n", 2);
}

int	lstsize(t_liste *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		i++;
		pile = pile->next;
	}
	return (i);
}
