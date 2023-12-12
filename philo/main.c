/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:01:23 by damachad          #+#    #+#             */
/*   Updated: 2023/12/12 17:15:20 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int main(int argc, char **argv)
{
	t_data	*data;
	
	if (argc == 5 || argc == 6)
	{
		init_data(data, argv);
	}
	else
	{
		printf("Error: Wrong number of arguments\n%s", ERROR_ARGS);
		return (1);
	}
	return (0);
}
