/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:01:23 by damachad          #+#    #+#             */
/*   Updated: 2023/12/28 11:11:11 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

bool	is_end(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->end));
	if ((philo->data->dead_philo) || (philo->data->finished_philos == philo->data->nbr_philos))
	{
		pthread_mutex_unlock(&(philo->data->end));
		return (true);
	}
	pthread_mutex_unlock(&(philo->data->end));
	return (false);
}

void	clean_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		pthread_mutex_destroy(&(data->philos[i].lock));
	}
	pthread_mutex_destroy(&(data->print));
	pthread_mutex_destroy(&(data->end));
	if (data->seats)
		free(data->seats);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	if (data)
		free(data);
}

int main(int argc, char **argv)
{
	t_data	*data;
	
	data = NULL;
	if (argc == 5 || argc == 6)
	{
		data = ft_calloc(1, sizeof(t_data));
		if (init_data(&data, argv))
		{
			printf("Error: Invalid arguments\n");
			return (1);
		}
		seat_philos(data);
		clean_data(data);
	}
	else
	{
		printf("Error: Wrong number of arguments\n%s", ERROR_ARGS);
		return (1);
	}
	return (0);
}
