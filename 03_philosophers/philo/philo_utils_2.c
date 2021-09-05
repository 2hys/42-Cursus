/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:08:46 by jiychoi           #+#    #+#             */
/*   Updated: 2021/09/05 10:31:03 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_death_print(t_philosopher *philosopher, int if_dead)
{
	int				timestamp;

	pthread_mutex_lock(&philosopher->philo_setting->death_mutex);
	timestamp = philo_timestamp(philosopher);
	if (if_dead == EVERYONE_ATE)
	{
		philosopher->philo_setting->if_dead = EVERYONE_ATE;
		printf("%dms\tEveryone ate %d time\n", timestamp,
			philosopher->philo_setting->num_to_eat);
	}
	else if (philosopher->philo_setting->if_dead == NO_ONE_DEAD)
	{
		philosopher->philo_setting->if_dead = ANYONE_DEAD;
		printf("%dms\t%d died\n", timestamp, philosopher->index + 1);
	}
	return (0);
}

int	philo_pause(t_philosopher *philosopher, int time_start, int time_threshold)
{
	while (philo_timestamp(philosopher) - time_start < time_threshold)
	{
		if (philo_timestamp(philosopher) - philosopher->time_eat_last_ms
			> philosopher->philo_setting->time_to_die)
			return (0);
	}
	return (1);
}

t_fork	*philo_destroy_fork(t_fork *fork, int end_index)
{
	int	index;

	index = 0;
	while (index < end_index)
		pthread_mutex_destroy(&fork[index++].mutex_id);
	free(fork);
	return (0);
}

t_philo_struct	*philo_free_struct(
	t_philo_setting *philo_setting,
	t_philosopher *philosophers,
	t_fork *forks,
	t_philo_struct *philo_struct)
{
	if (philosophers)
		free(philosophers);
	if (forks)
		philo_destroy_fork(forks, philo_setting->num_of_philo);
	if (philo_setting)
	{
		pthread_mutex_unlock(&philo_setting->death_mutex);
		pthread_mutex_destroy(&philo_setting->death_mutex);
		free(philo_setting);
	}
	if (philo_struct)
		free(philo_struct);
	return (0);
}
