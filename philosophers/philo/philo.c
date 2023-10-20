/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:12:45 by pgoudet           #+#    #+#             */
/*   Updated: 2022/01/26 12:34:37 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_data *data)
{
	int		i;
	int64_t	check;

	while (data->dead == false)
	{
		i = -1;
		while (++i < data->nb.nb_philo)
		{
			get_time(data, &data->thread[i].check);
			if (data->thread[i].new != 0 && (data->thread[i].check - \
				data->thread[i].new > data->nb.time_to_die))
			{
				data->dead = true;
				pthread_mutex_lock1(data, &data->talk_lock);
				printf("%lld %d died\n", \
					data->thread[i].check - data->start, i + 1);
				pmu1(data, &data->talk_lock);
				return ;
			}
		}
		usleep(500);
	}
}

int	init2(t_data *data, int argc, char **argv)
{
	int	i;

	i = -1;
	while (++i < data->nb.nb_philo)
	{
		pthread_mutex_init(&data->fork_lock[i].fork, NULL);
		data->fork_lock[i].bool = false;
	}
	pthread_mutex_init(&data->talk_lock.fork, NULL);
	data->talk_lock.bool = false;
	pthread_mutex_init(&data->dead_lock.fork, NULL);
	data->dead_lock.bool = false;
	pthread_mutex_init(&data->time_lock, NULL);
	if (data->nb.nb_philo == 1)
	{
		usleep(data->nb.time_to_die * 1000);
		printf("%d %d died\n", data->nb.time_to_die + 1, 1);
		free(data->thread);
		free(data->fork_lock);
		return (-1);
	}
	return (0);
}

int	init(t_data *data, int argc, char **argv)
{
	if (check_args(argv, argc) == -1)
		return (-1);
	data->nb = take_arg(argv);
	if (data->nb.check[0] == 'N')
		return (-1);
	data->thread = malloc(sizeof (t_thread) * data->nb.nb_philo + 1);
	data->fork_lock = malloc(sizeof(t_mutex) * data->nb.nb_philo);
	if (init2(data, argc, argv) == -1)
		return (-1);
	return (0);
}

void	finish(t_data *data)
{
	int	j;

	j = -1;
	while (++j < data->nb.nb_philo)
		pthread_mutex_destroy(&data->fork_lock[j].fork);
	pthread_mutex_destroy(&data->talk_lock.fork);
	pthread_mutex_destroy(&data->dead_lock.fork);
	pthread_mutex_destroy(&data->time_lock);
	free(data->thread);
	free(data->fork_lock);
}

int	main(int argc, char *argv[])
{
	int				i;
	int				j;
	t_data			data;

	argv++;
	if (init(&data, argc, argv) == -1)
		return (0);
	i = -1;
	init_struct(&data);
	data.dead = false;
	get_time(&data, &data.start);
	while (++i < data.nb.nb_philo)
	{
		data.thread[i].nb_meal = 0;
		pthread_create(&data.thread[i].thread, NULL,
			(void *)start_routine, &data);
	}
	usleep(100);
	check_death(&data);
	i = -1;
	while (++i < data.nb.nb_philo)
		pthread_join(data.thread[i].thread, NULL);
	finish(&data);
	return (0);
}
