/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:44:13 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/11 16:36:47 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_liste	*lastel(t_liste *liste)
{
	while (liste->next)
		liste = liste->next;
	return (liste);
}

void	display_pile_in_line(t_liste *pile)
{
	while (pile)
	{
		dprintf(1, "%d ", pile->nb);
		pile = pile->next;
	}
	write(1, "\n", 1);
}

int	max(t_liste *pile)
{
	int	max;

	max = INT_MIN;
	while (pile)
	{
		if (max < pile->nb)
			max = pile->nb;
		pile = pile->next;
	}
	return (max);
}
