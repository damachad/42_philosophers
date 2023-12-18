/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:42:03 by damachad          #+#    #+#             */
/*   Updated: 2023/12/18 15:23:38 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Start by picking up right fork */
void	even_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->r_fork));
	print_message(FORK, philo);
	pthread_mutex_lock(&(philo->l_fork));
	print_message(FORK, philo);
	print_message(EAT, philo);
	philo->nbr_meals++;
	philo->t_of_last_meal = get_time();
	ft_usleep(philo->data->t_eat * 1000);
	pthread_mutex_unlock(&(philo->r_fork));
	pthread_mutex_unlock(&(philo->l_fork));
}

/* Start by picking up left fork */
void	odd_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->l_fork));
	print_message(FORK, philo);
	pthread_mutex_lock(&(philo->r_fork));
	print_message(FORK, philo);
	print_message(EAT, philo);
	philo->nbr_meals++;
	philo->t_of_last_meal = get_time();
	ft_usleep(philo->data->t_eat * 1000);
	pthread_mutex_unlock(&(philo->l_fork));
	pthread_mutex_unlock(&(philo->r_fork));
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	int			i;

	i = -1;
	philo = (t_philo *)arg;
	while (philo->nbr_meals < philo->data->nbr_times_each_must_eat && \
	!(philo->data->dead_philo))
	{
		if (philo->id % 2 == 0)
			even_fork(philo);
		else
			odd_fork(philo);
		print_message(SLEEP, philo);
		ft_usleep(philo->data->t_sleep * 1000);
		print_message(THINK, philo);
	}
}

void	*monitor_routine(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
	while (!(data->dead_philo))
		continue ;
}
