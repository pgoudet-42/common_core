/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:46:46 by pgoudet           #+#    #+#             */
/*   Updated: 2022/01/26 12:35:43 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pthread_mutex_lock1(t_data *data, t_mutex *mutex)
{
	if (data->dead == 1)
		return (1);
	pthread_mutex_lock(&mutex->fork);
	mutex->bool = true;
	return (0);
}

int	pmu1(t_data *data, t_mutex *mutex)
{
	pthread_mutex_unlock(&mutex->fork);
	mutex->bool = false;
	return (0);
}

int	display(t_data *data, int id, char *mess, int time)
{
	if (pthread_mutex_lock1(data, &data->talk_lock) == 1)
		return (1);
	if (data->dead == 0)
		printf(mess, time, id + 1);
	return (pmu1(data, &data->talk_lock));
}

int	display2(t_data *data, int id, int time)
{
	id++;
	if (!data->dead)
	{
		pthread_mutex_lock1(data, &data->talk_lock);
		printf("%d %d has taken a fork\n%d %d has taken a fork\n%d %d is eating\n",
			time, id, time, id, time, id);
		pmu1(data, &data->talk_lock);
		return (0);
	}
	else
		return (1);
}
