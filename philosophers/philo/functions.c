/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:59:20 by pgoudet           #+#    #+#             */
/*   Updated: 2022/01/26 12:35:26 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	go_sleep(t_data *data, int id)
{
	int64_t	begin_func;

	get_time(data, &begin_func);
	if (display(data, id, "%lld %d is sleeping\n", \
		data->thread[id].check - data->start) == 1)
		return (1);
	while (data->thread[id].check - begin_func < data->nb.time_to_sleep)
	{
		if (get_time(data, &data->thread[id].check) == 1)
			return (1);
		usleep(250);
	}
	return (0);
}

int	routine(t_data *data, int id)
{
	while (data->dead == false)
	{
		if (take_fork(data, id) == 1)
			return (1);
		if (go_sleep(data, id) == 1)
			return (1);
		display(data, id, "%lld %d is thinking\n", \
		data->thread[id].check - data->start);
	}
	return (1);
}

void	*start_routine(t_data *data)
{
	static int	id;

	id++;
	routine(data, id - 1);
	return (data);
}
