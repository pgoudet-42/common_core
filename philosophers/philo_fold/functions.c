/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:45:25 by pgoudet           #+#    #+#             */
/*   Updated: 2021/06/14 09:02:28 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	get_time(int64_t *res, t_data *data)
{
	struct timeval		time;

	sem_wait(data->get_time.fork);
	gettimeofday(&time, NULL);
	*res = time.tv_sec * 1000 + time.tv_usec / 1000;
	sem_post(data->get_time.fork);
}

void	take_fork_unlock(t_data *data)
{
	sem_post(data->fork.fork);
	if (data->nb.nb_philo > 1)
	{
		sem_post(data->fork.fork);
		data->fork.nb_fork += 2;
	}
	else
		data->fork.nb_fork++;
	data->fork.bool = false;
}

void	take_fork_display(t_data *data, int id)
{
	sem_wait(data->fork.fork);
	data->nb_meal++;
	sem_wait(data->fork.fork);
	sem_wait(data->talk.fork);
	display2(data, id, data->time - data->test);
	get_time(&data->start, data);
	sem_post(data->talk.fork);
}

int	take_fork(t_data *data, int id)
{
	int64_t	start;

	take_fork_display(data, id);
	get_time(&start, data);
	while ((int)(data->time - start) < data->nb.time_to_eat)
		get_time(&data->time, data);
	go_sleep(data, id);
	return (0);
}

int	go_sleep(t_data *data, int id)
{
	int64_t	start;

	display(data, id, "%lld %d is sleeping\n", data->time - data->test);
	get_time(&start, data);
	get_time(&data->time, data);
	take_fork_unlock(data);
	while ((data->time - start) < data->nb.time_to_sleep)
		get_time(&data->time, data);
	thinking(data, id);
	return (0);
}
