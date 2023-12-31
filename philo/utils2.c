/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:57:52 by damachad          #+#    #+#             */
/*   Updated: 2023/12/31 09:41:52 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Returns 1 if c is a digit and 0 if it is not */
int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* Returns true if all strs only have digits */
bool	is_all_digit(char **strs)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (strs[++i])
	{
		j = -1;
		while (strs[i][++j])
			if (!ft_isdigit(strs[i][j]))
				return (false);
	}
	return (true);
}

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

int	one_philo(t_data *data)
{
	data->t_of_start = get_time();
	printf("%ld 1 %s\n", get_time() - data->t_of_start, FORK);
	usleep(data->t_die * 1000);
	printf("%ld 1 %s\n", get_time() - data->t_of_start, DIE);
	return (0);	
}
