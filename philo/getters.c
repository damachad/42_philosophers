/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:27:31 by damachad          #+#    #+#             */
/*   Updated: 2024/01/15 11:30:09 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_full_t_die(t_philo *philo)
{
	long int	full_t_die;

	pthread_mutex_lock(&(philo->full_t_die_lock));
	full_t_die = philo->full_t_die;
	pthread_mutex_unlock(&(philo->full_t_die_lock));
	return (full_t_die);
}

int	get_fin_philos(t_data *data)
{
	int	fin_philos;

	pthread_mutex_lock(&(data->fin_philos_lock));
	fin_philos = data->finished_philos;
	pthread_mutex_unlock(&(data->fin_philos_lock));
	return (fin_philos);
}

bool	get_dead_philo(t_data *data)
{
	bool	dead_philo;

	pthread_mutex_lock(&(data->dead_philo_lock));
	dead_philo = data->dead_philo;
	pthread_mutex_unlock(&(data->dead_philo_lock));
	return (dead_philo);
}

bool	is_end(t_philo *philo)
{
	if (get_dead_philo(philo->data) || \
	get_fin_philos(philo->data) >= philo->data->nbr_philos)
		return (true);
	return (false);
}
