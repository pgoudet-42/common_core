/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:41:13 by pgoudet           #+#    #+#             */
/*   Updated: 2021/07/17 15:06:54 by pgoudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef int	t_bool;
enum { false, true };

typedef struct s_nb
{
	int	nb_philo;
	int	time_to_eat;
	int	time_to_die;
	int	time_to_sleep;
	int	nb_of_meal;
}				t_nb;

typedef struct s_sem
{
	sem_t			*fork;
	int				nb_fork;
	t_bool			bool;
}				t_sem;

typedef struct s_thread
{
	pthread_t			thread;
	u_int64_t			start;
	int					nb_meal;
	u_int64_t			current_time;
	int					id;
}				t_thread;

typedef struct s_data
{
	t_sem		fork;
	t_nb		nb;
	int			nb_meal;
	int64_t		start;
	int64_t		test;
	t_sem		talk;
	int64_t		time;
	pthread_t	thread;
	t_bool		dead;
	t_sem		get_time;
	int			id;
}				t_data;

void	error_exit(char *mess);
void	*ft_malloc(int size);
void	ft_free(void *target);
void	display_tab(char **tab);
void	display(t_data *data, int id, char *mess, int64_t time);
void	display2(t_data *data, int id, int64_t time);
t_nb	take_arg(char **argv);
void	check_args(char **argv, int argc);
int		take_fork(t_data *data, int id);
void	init_struct(t_data *data, int *pid);
int		go_sleep(t_data *data, int id);
int		thinking(t_data *data, int id);
void	death_exit(t_data *data, int id);
void	is_alive(int64_t current, int64_t start, int id, t_data *data);
void	get_time(int64_t *res, t_data *data);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_itoa(int n);
double	ft_atoi(char *str);
int		ft_isalpha(int c);

#endif
