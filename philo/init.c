/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:05:20 by damachad          #+#    #+#             */
/*   Updated: 2023/12/12 17:24:18 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Allocate memory for data struct, set to NULLS and initialize with argv[] */
void	init_data(t_data *data, char **argv)
{
	data = ft_calloc(1, sizeof(t_data));
	data->nbr_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nbr_times_each_must_eat = ft_atoi(argv[5]);
}
