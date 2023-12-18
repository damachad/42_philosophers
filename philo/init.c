/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:05:20 by damachad          #+#    #+#             */
/*   Updated: 2023/12/18 11:45:31 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print_ID(void *tid)
{
	printf("Thread ID: %lu\n", *(pthread_t *)tid);
	return (NULL);
}

int	seat_philos(t_data *data)
{
	// int				i;
	pthread_t		philo1, philo2;
	// pthread_t		monitor;
	// pthread_mutex_t	*forks;

	// i = -1;
	// philos = ft_calloc(data->nbr_philos, sizeof(pthread_t));
	// forks = ft_calloc(data->nbr_philos, sizeof(pthread_mutex_t));
	// while (++i < data->nbr_philos)
	// 	pthread_mutex_init(&forks[i], NULL);
	// i = -1;
	// pthread_create(&monitor, NULL, &monitor_routine, data);
	// while (++i < data->nbr_philos)
	// {
	pthread_create(&philo1, NULL, print_ID, &philo1);
	pthread_create(&philo2, NULL, print_ID, &philo2);
	// }
	// i = -1;
	// while (++i < data->nbr_philos)
	// {
	pthread_join(philo1, NULL);
	pthread_join(philo2, NULL);
	// }
	// pthread_join(monitor, NULL);
	// i = -1;
	// while (++i < data->nbr_philos)
	// 	pthread_mutex_destroy(&forks[i]);
	return (0);
}

void	init_philos(t_data *data)
{
	int	i;

	i = -1;
	data->philos = ft_calloc(data->nbr_philos, sizeof(t_philo));
	while (++i < data->nbr_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i + 1];
		data->philos[i].data = data;
	}
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
	data->forks = ft_calloc(data->nbr_philos, sizeof(pthread_mutex_t));
	init_philos(data);
	return (0);
}
