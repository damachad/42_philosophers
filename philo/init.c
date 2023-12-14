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
	data->forks = ft_calloc(data->nbr_philos, sizeof(int));
	while (++i < data->nbr_philos)
		data->forks[i] = i;
	if (data->t_die < 60 || data->t_eat < 60 || data->t_sleep < 60 || \
	data->nbr_philos < 1 || data->nbr_times_each_must_eat < 0 || \
	data->nbr_philos > 200)
	{
		free(data->forks);
		free(data);
		return (1);
	}
	return (0);
}
