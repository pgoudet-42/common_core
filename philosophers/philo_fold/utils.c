/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:34:26 by pgoudet           #+#    #+#             */
/*   Updated: 2022/01/25 13:03:07 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	error_exit(char *mess)
{
	write(1, "error in:", 9);
	write(1, mess, ft_strlen(mess));
	exit(-1);
}

void	display(t_data *data, int id, char *mess, int64_t time)
{
	sem_wait(data->talk.fork);
	if (data->dead == 0)
	{
		data->talk.bool = true;
		printf(mess, time, id + 1);
		sem_post(data->talk.fork);
	}
	else
	{
		sem_post(data->talk.fork);
		exit(0);
	}
	data->talk.bool = false;
}

void	display2(t_data *data, int id, int64_t time)
{
	if (data->dead == 0)
	{
		data->talk.bool = true;
		printf("%lld %d has taken a fork\n%lld %d has taken \
a fork\n%lld %d is eating\n", time, id + 1, time, id + 1, time, id + 1);
	}
	else
		exit(0);
}

void	init_struct(t_data *data, int *pid)
{
	data->nb_meal = 0;
	data->fork.bool = false;
	data->talk.bool = false;
	data->time = 0;
	if (data->nb.nb_philo == 1)
	{
		usleep(data->nb.time_to_die * 1000);
		free(pid);
		is_alive(data->nb.time_to_die, -1, 0, data);
	}
}
