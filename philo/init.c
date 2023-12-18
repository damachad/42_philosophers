/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:05:20 by damachad          #+#    #+#             */
/*   Updated: 2023/12/18 17:56:20 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	seat_philos(t_data *data)
{
	int				i;
	pthread_t		monitor;

	i = -1;
	while (++i < data->nbr_philos)
		pthread_mutex_init(&(data->forks[i]), NULL);
	i = -1;
	pthread_mutex_init(&(data->print), NULL);
	pthread_mutex_init(&(data->end), NULL);
	pthread_create(&monitor, NULL, &monitor_routine, data);
	while (++i < data->nbr_philos)
	{
		pthread_create(&(data->seats[i]), NULL, &philo_routine, &(data->philos[i]));
		pthread_detach(data->seats[i]);
	}
	i = -1;
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < data->nbr_philos)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->print));
	pthread_mutex_destroy(&(data->end));
	return (0);
}

void	init_philos(t_data *data)
{
	int	i;

	i = -1;
	data->philos = ft_calloc(data->nbr_philos, sizeof(t_philo));
	while (++i < data->nbr_philos - 1)
	{
		data->philos[i].id = i + 1;
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i + 1];
		data->philos[i].data = data;
	}
	data->philos[i].id = i + 1;
	data->philos[i].l_fork = &data->forks[i];
	data->philos[i].r_fork = &data->forks[0];
	data->philos[i].data = data;
}

/* Allocate memory for data struct, set to NULLS and initialize with argv[] */
int	init_data(t_data *data, char **argv)
{
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
	data->seats = ft_calloc(data->nbr_philos, sizeof(pthread_t));
	data->forks = ft_calloc(data->nbr_philos, sizeof(pthread_mutex_t));
	init_philos(data);
	return (0);
}
