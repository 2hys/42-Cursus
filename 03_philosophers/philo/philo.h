/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 15:23:02 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/04 17:13:26 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# define FORK_1	1
# define FORK_0	0
# define NO_ONE_DEAD 0
# define ANYONE_DEAD 1

typedef struct s_philo_setting
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_to_eat;
	int				num_of_philo;
	int				num_of_philo_ate;
	int				if_dead;
	time_t			time_start_s;
	suseconds_t		time_start_us;
}				t_philo_setting;

typedef struct s_fork
{
	int				index;
	int				fork;
	pthread_mutex_t	mutex_id;
}			t_fork;

typedef struct s_philosopher
{
	t_philo_setting	*philo_setting;
	int				index;
	int				num_ate;
	pthread_t		thread_id;
	t_fork			*fork_left;
	t_fork			*fork_right;
	int				time_eat_last_ms;
}			t_philosopher;

typedef struct s_philo_struct
{
	t_philo_setting	*philo_setting;
	t_philosopher	*philosophers;
	t_fork			*forks;
}				t_philo_struct;

/*
	** Philosophers: Main function
*/
t_philo_struct	*philo_init_struct(int argc, char *argv[]);
void			*philo_thread_func(void *data);

/*
	** Philosophers: Utilities
*/
int				ft_atoi(const char *str);
void			*philo_death_print(t_philosopher *philosopher);
int				philo_timestamp(t_philosopher *philosopher);
t_fork			*philo_destroy_fork(t_fork *fork, int end_index);
int				philo_pause(
					t_philosopher *philosopher,
					int time_start,
					int time_threshold);
t_philo_struct	*philo_free_struct(
					t_philo_setting *philo_setting,
					t_philosopher *philosophers,
					t_fork *forks,
					t_philo_struct *philo_struct);

#endif
