/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:01:23 by damachad          #+#    #+#             */
/*   Updated: 2023/12/18 17:53:50 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	clean_data(t_data *data)
{
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
		if (init_data(data, argv))
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
