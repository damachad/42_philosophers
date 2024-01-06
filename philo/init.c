/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:05:20 by damachad          #+#    #+#             */
/*   Updated: 2024/01/04 15:13:18 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_start_time(t_philo *philo)
{
	static bool	once;

	pthread_mutex_lock(&philo->data->end);
	if (!once)
	{
		once = true;
		philo->data->t_of_start = get_time();
	}
	pthread_mutex_unlock(&philo->data->end);
}

int	seat_philos(t_data *d)
{
	int				i;
	pthread_t		monitor;

	i = -1;
	while (++i < d->nbr_philos)
		pthread_mutex_init(&(d->forks[i]), NULL);
	i = -1;
	pthread_mutex_init(&(d->print), NULL);
	pthread_mutex_init(&(d->end), NULL);
	if (d->nbr_t_eat > 0)
		pthread_create(&monitor, NULL, &monitor_routine, d);
	while (++i < d->nbr_philos)
	{
		pthread_mutex_init(&(d->philos[i].lock), NULL);
		pthread_create(&(d->seats[i]), NULL, &ph_routine, &(d->philos[i]));
	}
	if (d->nbr_t_eat > 0)
		pthread_join(monitor, NULL);
	i = -1;
	while (++i < d->nbr_philos)
		pthread_join(d->seats[i], NULL);
	return (0);
}

/* Initialize philos struct with id, forks and a pointer to data */
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
int	init_data(t_data **data, char **argv)
{
	t_data	*tmp;

	tmp = *data;
	if (!is_all_digit(argv + 1))
		return (1);
	tmp->nbr_philos = simple_atoi(argv[1]);
	tmp->t_die = simple_atoi(argv[2]);
	tmp->t_eat = simple_atoi(argv[3]);
	tmp->t_sleep = simple_atoi(argv[4]);
	if (argv[5])
		tmp->nbr_t_eat = simple_atoi(argv[5]);
	if (tmp->t_die < 60 || tmp->t_eat < 60 || tmp->t_sleep < 60 || \
	tmp->nbr_philos < 1 || tmp->nbr_t_eat < 0 || \
	tmp->nbr_philos > 200)
		return (2);
	tmp->seats = ft_calloc(tmp->nbr_philos, sizeof(pthread_t));
	tmp->forks = ft_calloc(tmp->nbr_philos, sizeof(pthread_mutex_t));
	init_philos(*data);
	return (0);
}
