/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 09:30:45 by pgoudet           #+#    #+#             */
/*   Updated: 2021/06/14 09:01:35 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	is_alive(int64_t current, int64_t start, int id, t_data *data)
{
	sem_wait(data->talk.fork);
	if (current - start > data->nb.time_to_die)
	{
		data->dead = 1;
		printf("%lld %d died\n", current - data->test, id + 1);
		exit(0);
	}
	else if (data->nb_meal == data->nb.nb_of_meal + 1)
	{
		write(1, "end\n", 4);
		exit(0);
	}
	sem_post(data->talk.fork);
}

int	thinking(t_data *data, int id)
{
	get_time(&data->time, data);
	display(data, id, "%lld %d is thinking\n", data->time - data->test);
	take_fork(data, id);
	return (0);
}
