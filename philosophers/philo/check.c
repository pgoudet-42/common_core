/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 06:39:01 by pgoudet           #+#    #+#             */
/*   Updated: 2021/07/24 16:12:26 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	check_args(char **argv, int argc)
{
	char	**run;
	char	*run2;

	run = argv;
	if (argc != 5 && argc != 6)
		return (error_exit("check_args1"));
	while (*run)
	{
		run2 = *run;
		while (**run)
		{
			if (**run > '9' || **run < '0')
				return (error_exit("check_args2"));
			(*run)++;
		}
		*run = run2;
		run++;
	}
	return (0);
}

int	take_arg_verif(char *arg)
{
	int		check;
	char	*checkbis;

	check = (int)ft_atoi(arg);
	checkbis = ft_itoa(check);
	if (ft_strcmp(checkbis, arg) != 0)
		return (error_exit("check_args3"));
	free(checkbis);
	return (check);
}

t_nb	take_arg2(char **argv)
{
	t_nb	nb;

	nb.nb_philo = take_arg_verif(*argv);
	if (nb.nb_philo > 200 || nb.nb_philo <= 0)
	{
		nb.check[0] = 'N';
		return (nb);
	}
	argv++;
	nb.time_to_die = take_arg_verif(*argv);
	argv++;
	nb.time_to_eat = take_arg_verif(*argv);
	argv++;
	nb.time_to_sleep = take_arg_verif(*argv);
	argv++;
	return (nb);
}

t_nb	take_arg(char **argv)
{
	t_nb	nb;

	nb = take_arg2(argv);
	if (nb.check[0] == 'N')
		return (nb);
	argv += 4;
	if (*argv)
		nb.nb_of_meal = take_arg_verif(*argv);
	else
		nb.nb_of_meal = -1;
	nb.check[0] = 'Y';
	return (nb);
}
