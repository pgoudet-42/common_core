/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:48:10 by pgoudet           #+#    #+#             */
/*   Updated: 2022/01/26 12:31:31 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork_unlock(t_data *data, int id)
{
	int	ret;

	ret = 0;
	if (pmu1(data, &data->fork_lock[id]) == 1)
		ret = 1;
	if (pmu1(data, &data->fork_lock[(id + 1) \
		% data->nb.nb_philo]) == 1)
		ret = 1;
	return (ret);
}

int	take_fork_lock(t_data *data, int id)
{
	if (pthread_mutex_lock1(data, &data->fork_lock[id]) == 1 \
		|| pthread_mutex_lock1(data, &data->fork_lock[(id + 1) \
		% data->nb.nb_philo]) == 1)
	{
		if (data->fork_lock[id].bool == true)
			pmu1(data, &data->fork_lock[id]);
		if (data->fork_lock[(id + 1) % data->nb.nb_philo].bool == true)
			pmu1(data, &data->fork_lock[(id + 1) \
			% data->nb.nb_philo]);
		return (1);
	}
	get_time(data, &data->thread[id].new);
	get_time(data, &data->thread[id].check);
	if (display2(data, id, (data->thread[id].check - data->start)) == 1)
	{
		if (data->fork_lock[id].bool == true)
			pmu1(data, &data->fork_lock[id]);
		if (data->fork_lock[(id + 1) % data->nb.nb_philo].bool == true)
			pmu1(data, &data->fork_lock[(id + 1) % data->nb.nb_philo]);
		return (1);
	}
	if (++data->thread[id].nb_meal > data->nb.nb_of_meal \
		&& data->nb.nb_of_meal > 0)
		data->dead = true;
	return (0);
}

int	take_fork(t_data *data, int id)
{
	int64_t	begin_func;

	if (take_fork_lock(data, id) == 1)
		return (1);
	get_time(data, &begin_func);
	while (data->thread[id].check - begin_func < data->nb.time_to_eat)
	{
		if (get_time(data, &data->thread[id].check) == 1)
			return (take_fork_unlock(data, id));
		usleep(250);
	}
	if (take_fork_unlock(data, id) == 1)
		return (1);
	return (0);
}
