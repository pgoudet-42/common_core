/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:25:49 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/11 12:35:21 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	add_front(t_liste **alst, t_liste *new)
{
	t_liste	*tmp;

	if (*alst == NULL)
	{
		new->next = NULL;
		new->previous = NULL;
		*alst = new;
	}
	else
	{
		tmp = *alst;
		(*alst)->previous = new;
		*alst = new;
		(*alst)->next = tmp;
		(*alst)->previous = NULL;
		tmp->previous = *alst;
	}
}

void	add_back(t_liste **alst, t_liste *new)
{
	t_liste	*run;

	run = *alst;
	if (*alst == NULL)
	{
		new->next = NULL;
		new->previous = NULL;
		*alst = new;
	}
	else
	{
		while (run->next != NULL)
			run = run->next;
		run->next = new;
		new->next = NULL;
		new->previous = run;
	}
}

void	rm_el(t_liste **pile, t_liste *el)
{
	t_liste	*tmp;
	t_liste	*tmp2;

	if (lstsize(*pile) == 1)
	{
		*pile = NULL;
	}
	else if (el->previous == NULL)
	{
		(*pile) = el->next;
		(*pile)->previous = NULL;
	}
	else if (el->next == NULL)
	{
		tmp = el->previous;
		tmp->next = NULL;
	}
	else
	{
		tmp = el->next;
		tmp2 = el->previous;
		tmp2->next = tmp;
		tmp->previous = tmp2;
	}
}

void	display_pile(t_liste *pile, char *mess)
{
	static int	i;

	dprintf(1, "________%d________\n", i);
	dprintf(1, "%s\n", mess);
	while (pile)
	{
		dprintf(1, "%d\n", pile->nb);
		pile = pile->next;
	}
	i++;
}
