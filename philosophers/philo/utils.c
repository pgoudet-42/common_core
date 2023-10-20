/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:34:26 by pgoudet           #+#    #+#             */
/*   Updated: 2021/08/13 11:52:44 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_exit(char *mess)
{
	write(1, "error in:", 9);
	write(1, mess, ft_strlen(mess));
	return (-1);
}

void	init_struct(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb.nb_philo)
	{
		data->fork_lock[i].bool = false;
		i++;
	}
	if (data->nb.nb_philo == 1)
	{
		usleep(data->nb.time_to_die * 1000);
		printf("%d %d died\n", data->nb.time_to_die * 1000 + 1, 1);
	}
}
