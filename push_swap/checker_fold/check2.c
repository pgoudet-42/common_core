/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:47:14 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/12 08:19:15 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	check_pile(t_liste *pile_a)
{
	t_liste	*run;
	t_liste	*tmp;

	while (pile_a->next)
	{
		tmp = pile_a;
		run = pile_a->next;
		while (run)
		{
			if (run->nb == tmp->nb)
				return (-1);
			run = run->next;
		}
		pile_a = pile_a->next;
	}
	return (0);
}

static void	arg_to_int_bis(char **argv, t_liste **pile_a)
{
	t_liste	*maillon;
	int		i;
	char	*tmp;

	i = -1;
	while (argv[++i])
	{
		maillon = malloc(sizeof(t_liste));
		maillon->nb = ft_atoi(argv[i]);
		tmp = ft_itoa(maillon->nb);
		if (ft_strcmp(tmp, argv[i]) != 0)
			error_exit("arg_to_int");
		else
		{
			maillon->next = NULL;
			maillon->previous = NULL;
			add_back(pile_a, maillon);
			free(tmp);
		}
	}
}

t_liste	*arg_to_int(char **argv, int argc)
{
	int		j;
	t_liste	*pile_a;

	j = -1;
	pile_a = NULL;
	if (argc ==2)
		argv = ft_split((const char *)argv[1], ' ');
	else
		argv++;
	arg_to_int_bis(argv, &pile_a);
	if (check_pile(pile_a) == -1)
		error_exit("check_pile");
	return (pile_a);
}
