/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:42:03 by damachad          #+#    #+#             */
/*   Updated: 2023/12/14 14:46:47 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_data		*data;
	int			i;

	i = -1;
	data = (t_data *)arg;
	while (++i < data->nbr_times_each_must_eat || !data->dead_philo)
	{
		pthread_mutex_lock(&data->mutex[i]);
		printf("Philosopher %d has taken a fork\n", i);
		pthread_mutex_lock(&data->mutex[i + 1]);
		printf("Philosopher %d has taken a fork\n", i);
		printf("Philosopher %d is eating\n", i);
		usleep(data->t_eat * 1000);
		pthread_mutex_unlock(&data->mutex[i]);
		pthread_mutex_unlock(&data->mutex[i + 1]);
		printf("Philosopher %d is sleeping\n", i);
		usleep(data->t_sleep * 1000);
		printf("Philosopher %d is thinking\n", i);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_data		*data;
	int			i;

	i = -1;
	data = (t_data *)arg;
	while (++i < data->nbr_philos)
	{
		// if (get_time() - data->philos[i] > data->t_die)
		// {
		// 	printf("Philosopher %d died\n", i);
		// 	data->dead_philo = true;
		// 	return (NULL);
		// }
	}
	return (NULL);
}
