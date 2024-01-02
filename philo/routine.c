/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:42:03 by damachad          #+#    #+#             */
/*   Updated: 2024/01/02 18:14:12 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_routine(void *arg)
{
	t_philo		*philo;
	
	philo = (t_philo *)arg;
	while (!is_end(philo))
	{
		pthread_mutex_lock(&(philo->lock));
		if (get_time() >= philo->t_to_die)
			print_message(DIE, philo);
		if (philo->data->nbr_times_each_must_eat && philo->nbr_meals == philo->data->nbr_times_each_must_eat)
		{
			pthread_mutex_lock(&(philo->data->end));
			philo->data->finished_philos++;
			pthread_mutex_unlock(&(philo->data->end));
		}
		pthread_mutex_unlock(&(philo->lock));
	}
	return (NULL);
}

/* Start by picking up right fork */
void	even_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_message(FORK, philo);
	pthread_mutex_lock(philo->l_fork);
	print_message(FORK, philo);
	print_message(EAT, philo);
	pthread_mutex_lock(&(philo->lock));
	philo->t_to_die = philo->data->t_die + get_time();
	philo->nbr_meals++;
	ft_usleep(philo->data->t_eat * 1000);
	pthread_mutex_unlock(&(philo->lock));
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

/* Start by picking up left fork */
void	odd_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_message(FORK, philo);
	pthread_mutex_lock(philo->r_fork);
	print_message(FORK, philo);
	print_message(EAT, philo);
	pthread_mutex_lock(&(philo->lock));
	philo->t_to_die = philo->data->t_die + get_time();
	philo->nbr_meals++;
	ft_usleep(philo->data->t_eat * 1000);
	pthread_mutex_unlock(&(philo->lock));
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	philo->t_to_die = philo->data->t_die + get_time();
	pthread_create(&(philo->checker), NULL, &check_routine, philo);
	while (!is_end(philo))
	{
		if (philo->id % 2 == 0)
			even_fork(philo);
		else
			odd_fork(philo);
		print_message(SLEEP, philo);
		ft_usleep(philo->data->t_sleep * 1000);
		print_message(THINK, philo);
	}
	pthread_join(philo->checker, NULL);
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
	while (data->dead_philo == false)
	{
		pthread_mutex_lock(&(data->end));
		if ((data->finished_philos == data->nbr_philos))
		{
			pthread_mutex_unlock(&(data->end));
			return (NULL);
		}
		pthread_mutex_unlock(&(data->end));
	}
	return (NULL);
}
