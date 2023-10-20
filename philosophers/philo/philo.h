/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:29:51 by pgoudet           #+#    #+#             */
/*   Updated: 2022/01/26 12:31:20 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef int	t_bool;
enum { false, true };

typedef struct s_nb
{
	int		nb_philo;
	int		time_to_eat;
	int		time_to_die;
	int		time_to_sleep;
	int		nb_of_meal;
	char	check[1];
}				t_nb;

typedef struct s_mutex
{
	pthread_mutex_t	fork;
	t_bool			bool;
}				t_mutex;

typedef struct s_thread
{
	pthread_t			thread;
	int64_t				check;
	int64_t				new;
	int					nb_meal;
}				t_thread;

typedef struct s_data
{
	t_thread		*thread;
	t_mutex			*fork_lock;
	t_nb			nb;
	int64_t			start;
	t_mutex			talk_lock;
	t_bool			dead;
	pthread_mutex_t	time_lock;
	t_mutex			dead_lock;
}				t_data;

int		error_exit(char *mess);
void	*ft_malloc(int size);
void	ft_free(void *target);
void	display_tab(char **tab);
int		display(t_data *data, int id, char *mess, int time);
int		display2(t_data *data, int id, int time);
t_nb	take_arg(char **argv);
int		check_args(char **argv, int argc);
int		take_fork(t_data *data, int id);
int		take_fork_unlock(t_data *data, int id);
void	init_struct(t_data *data);
void	check_1(t_data *data, int id);
int		get_time(t_data *data, int64_t *check);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_itoa(int n);
double	ft_atoi(char *str);
int		ft_isalpha(int c);
int		pthread_mutex_lock1(t_data *data, t_mutex *mutex);
int		pmu1(t_data *data, t_mutex *mutex);
int		read_death(t_data *data);
int		thinking(t_data *data, int id);
int		go_sleep(t_data *data, int id);
int		take_fork(t_data *data, int id);
int		routine(t_data *data, int id);
void	*start_routine(t_data *data);
#endif