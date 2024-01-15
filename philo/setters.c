/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_later.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:58:12 by damachad          #+#    #+#             */
/*   Updated: 2024/01/15 11:28:10 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_full_t_die(t_philo *philo)
{
	pthread_mutex_lock(&(philo->full_t_die_lock));
	philo->full_t_die = philo->data->t_die + get_time();
	pthread_mutex_unlock(&(philo->full_t_die_lock));
}

void	update_fin_philos(t_data *data)
{
	pthread_mutex_lock(&(data->fin_philos_lock));
	data->finished_philos++;
	pthread_mutex_unlock(&(data->fin_philos_lock));
}

void	update_dead_philo(t_data *data)
{
	pthread_mutex_lock(&(data->dead_philo_lock));
	data->dead_philo = true;
	pthread_mutex_unlock(&(data->dead_philo_lock));
}

bool	philo_died(t_philo *philo)
{
	bool		result;

	result = false;
	if (get_time() > get_full_t_die(philo))
		result = true;
	return (result);
}
