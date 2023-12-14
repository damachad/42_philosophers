/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:05:20 by damachad          #+#    #+#             */
/*   Updated: 2023/12/14 14:38:53 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	seat_philos(t_data *data)
{
	int				i;
	pthread_t		*philos;
	pthread_t		monitor;
	pthread_mutex_t	*forks;

	i = -1;
	philos = ft_calloc(data->nbr_philos, sizeof(pthread_t));
	forks = ft_calloc(data->nbr_philos, sizeof(pthread_mutex_t));
	while (++i < data->nbr_philos)
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	pthread_create(&monitor, NULL, &monitor_routine, data);
	while (++i < data->nbr_philos)
	{
		pthread_create(&philos[i], NULL, &philo_routine, data);
		pthread_detach(philos[i]);
	}
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < data->nbr_philos)
		pthread_mutex_destroy(&forks[i]);
	return (0);
}

/* Allocate memory for data struct, set to NULLS and initialize with argv[] */
int	init_data(t_data *data, char **argv)
{
	int	i;

	i = -1;
	data = ft_calloc(1, sizeof(t_data));
	data->nbr_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nbr_times_each_must_eat = ft_atoi(argv[5]);
	if (data->t_die < 60 || data->t_eat < 60 || data->t_sleep < 60 || \
	data->nbr_philos < 1 || data->nbr_times_each_must_eat < 0 || \
	data->nbr_philos > 200)
	{
		free(data);
		return (1);
	}
	return (0);
}
