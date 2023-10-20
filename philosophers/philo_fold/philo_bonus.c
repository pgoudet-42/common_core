/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:09:16 by pgoudet           #+#    #+#             */
/*   Updated: 2021/07/17 15:07:05 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_forks(int nb, pid_t *pid)
{
	int	i;

	i = -1;
	while (++i < nb)
		kill(pid[i], SIGKILL);
	free(pid);
}

void	start_routine(t_data *data)
{
	get_time(&data->start, data);
	while (1)
	{
		get_time(&data->time, data);
		usleep(100);
		is_alive(data->time, data->start, data->id + 1, data);
	}
}

void	init(char **argv, int argc, t_data *data, int **pid)
{
	argv++;
	check_args(argv, argc);
	data->nb = take_arg(argv);
	data->fork.nb_fork = data->nb.nb_philo;
	sem_unlink("/test");
	sem_unlink("/test2");
	sem_unlink("/test3");
	data->fork.fork = sem_open("/test", O_CREAT, S_IRWXU, data->nb.nb_philo);
	data->fork.fork = sem_open("/test", 0);
	data->talk.fork = sem_open("/test2", O_CREAT, S_IRWXU, 1);
	data->talk.fork = sem_open("/test2", 0);
	data->get_time.fork = sem_open("/test3", O_CREAT, S_IRWXU, 1);
	data->get_time.fork = sem_open("/test3", 0);
	*pid = malloc(sizeof(pid_t) * data->nb.nb_philo);
	data->dead = 0;
}

void	while_main(pid_t *pid, int i, t_data *data, int *status)
{
	if (pid[i] == 0)
	{
		get_time(&data->start, data);
		get_time(&data->time, data);
		pthread_create(&data->thread, NULL,
			(void *)start_routine, data);
		take_fork(data, i);
	}
	else if (i == data->nb.nb_philo - 1)
	{
		waitpid(-1, status, 0);
		kill_forks(data->nb.nb_philo, pid);
		sem_post(data->talk.fork);
		sem_unlink("/test");
		sem_unlink("/test2");
	}
	usleep(50);
}

int	main(int argc, char *argv[])
{
	int			i;
	int			status;
	pid_t		*pid;
	t_data		data;

	init(argv, argc, &data, &pid);
	i = -1;
	init_struct(&data, pid);
	data.id = -1;
	get_time(&data.test, &data);
	while (++i < data.nb.nb_philo)
	{
		data.id++;
		pid[i] = fork();
		while_main(pid, i, &data, &status);
	}
	return (0);
}
