/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 09:30:45 by pgoudet           #+#    #+#             */
/*   Updated: 2022/01/25 13:03:17 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(t_data *data, int64_t *res)
{
	struct timeval	time;

	if (data->dead == 1)
		return (1);
	pthread_mutex_lock(&data->time_lock);
	gettimeofday(&time, NULL);
	*res = time.tv_sec * 1000 + time.tv_usec / 1000;
	pthread_mutex_unlock(&data->time_lock);
	return (0);
}
