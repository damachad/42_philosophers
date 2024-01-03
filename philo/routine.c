/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:42:03 by damachad          #+#    #+#             */
/*   Updated: 2024/01/03 15:25:42 by damachad         ###   ########.fr       */
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
		if (philo->full_t_die <= get_time())
			print_message(DIE, philo);
		if (philo->data->nbr_t_eat && philo->nbr_meals == philo->data->nbr_t_eat)
		{
			pthread_mutex_lock(&(philo->data->end));
			philo->data->finished_philos++;
			pthread_mutex_unlock(&(philo->data->end));
		}
		pthread_mutex_unlock(&(philo->lock));
	}
	return (NULL);
}

void	eat(t_philo *philo, pthread_mutex_t *f1, pthread_mutex_t *f2)
{
	// int	id;
	// id = philo->id - 1;
	// if (odd && id != philo->data->nbr_philos - 1)
	// 	pthread_mutex_lock(&(philo->data->philos[id + 1].lock));
	// else if (odd && id == philo->data->nbr_philos - 1)
	// 	pthread_mutex_lock(&(philo->data->philos[0].lock));
	// else
	// 	pthread_mutex_lock(&(philo->data->philos[id - 1].lock));
	pthread_mutex_lock(f1);
	print_message(FORK, philo);
	pthread_mutex_lock(f2);
	print_message(FORK, philo);
	pthread_mutex_lock(&(philo->lock));
	philo->nbr_meals++;
	print_message(EAT, philo);
	philo->full_t_die = philo->data->t_die + get_time();
	ft_usleep(philo->data->t_eat * 1000);
	pthread_mutex_unlock(&(philo->lock));
	pthread_mutex_unlock(f1);
	pthread_mutex_unlock(f2);
	// if (odd && id != philo->data->nbr_philos - 1)
	// 	pthread_mutex_unlock(&(philo->data->philos[id + 1].lock));
	// else if (odd && id == philo->data->nbr_philos - 1)
	// 	pthread_mutex_unlock(&(philo->data->philos[0].lock));
	// else
	// 	pthread_mutex_unlock(&(philo->data->philos[id - 1].lock));
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	philo->full_t_die = philo->data->t_die + get_time();
	pthread_create(&(philo->checker), NULL, &check_routine, philo);
	while (!is_end(philo))
	{
		if (philo->id % 2 == 0)
			eat(philo, philo->l_fork, philo->r_fork);
		else
		{
			ft_usleep(philo->data->t_eat * 1000 / 2);
			eat(philo, philo->r_fork, philo->l_fork);
		}
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
	while (!data->dead_philo)
	{
		pthread_mutex_lock(&(data->end));
		if ((data->finished_philos == data->nbr_philos))
		{
			data->dead_philo = true;
			pthread_mutex_unlock(&(data->end));
			return (NULL);
		}
		pthread_mutex_unlock(&(data->end));
	}
	return (NULL);
}
