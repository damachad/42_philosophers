/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:42:03 by damachad          #+#    #+#             */
/*   Updated: 2024/01/15 18:01:58 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo, pthread_mutex_t *f1, pthread_mutex_t *f2)
{
	pthread_mutex_lock(f1);
	print_message(FORK, philo);
	pthread_mutex_lock(f2);
	print_message(FORK, philo);
	print_message(EAT, philo);
	philo->nbr_meals++;
	update_full_t_die(philo);
	ft_usleep(philo->data->t_eat * 1000);
	pthread_mutex_unlock(f1);
	pthread_mutex_unlock(f2);
	if (philo->data->nbr_t_eat && philo->nbr_meals >= philo->data->nbr_t_eat \
	&& !philo->full)
	{
		update_fin_philos(philo->data);
		philo->full = true;
	}
}

void	before_simulation(t_philo *philo)
{
	while (!is_start(philo->data))
		ft_usleep(1000);
	update_full_t_die(philo);
	if (philo->id % 2)
		ft_usleep(50 * 1000);
}

void	*ph_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	update_full_t_die(philo);
	if (philo->data->nbr_philos == 1)
		return (one_philo(philo));
	before_simulation(philo);
	while (!is_end(philo))
	{
		if (philo->id % 2 == 0)
			eat(philo, philo->l_fork, philo->r_fork);
		else
		{
			if (philo->data->nbr_philos % 2)
				ft_usleep(philo->data->t_eat / 2 * 1000 + 20);
			eat(philo, philo->r_fork, philo->l_fork);
		}
		if (is_end(philo))
			break ;
		print_message(SLEEP, philo);
		ft_usleep(philo->data->t_sleep * 1000);
		print_message(THINK, philo);
	}
	return (NULL);
}

void	*monitor2_routine(void *arg)
{
	t_data		*data;

	data = (t_data *)arg;
	while (!is_end(data->philos))
	{
		if ((get_fin_philos(data) == data->nbr_philos))
		{
			update_dead_philo(data);
			return (NULL);
		}
	}
	return (NULL);
}

void	*monitor1_routine(void *arg)
{
	int		i;
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)arg;
	philos = data->philos;
	i = -1;
	while (++i < data->nbr_philos && !get_dead_philo(data))
	{
		if (!get_dead_philo(data) && get_full_t_die(&(philos[i])) < get_time())
		{
			print_message(DIE, &(philos[i]));
			update_dead_philo(data);
			break ;
		}
		if (i == data->nbr_philos - 1)
			i = -1;
	}
	return (NULL);
}
