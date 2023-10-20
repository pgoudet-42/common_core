/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:08:22 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 07:50:00 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	find_max(t_liste *a)
{
	int	max;
	int	pos;
	int	compt;

	max = INT_MIN;
	pos = 0;
	compt = 0;
	if (a == NULL)
		return (-1);
	while (a)
	{
		if (max < a->nb)
		{
			pos = compt;
			max = a->nb;
		}
		a = a->next;
		compt++;
	}
	return (pos);
}

int	find_min(t_liste *a)
{
	int	min;
	int	pos;
	int	compt;

	min = INT_MAX;
	pos = 0;
	compt = 0;
	if (a == NULL)
		return (-1);
	while (a)
	{
		if (min > a->nb)
		{
			pos = compt;
			min = a->nb;
		}
		a = a->next;
		compt++;
	}
	return (pos);
}

void	*find_last_el(t_liste *liste)
{
	t_liste	*run;

	run = liste;
	while (run)
		run = run->next;
	return (run);
}
