/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:46:02 by damachad          #+#    #+#             */
/*   Updated: 2024/01/16 13:39:29 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* More precise version of usleep */
void	ft_usleep(int time_in_us)
{
	long int	start;

	start = get_time();
	while ((get_time() - start) * 1000 < time_in_us)
		usleep(time_in_us / 1000);
}

/* Print a message with current time and philo id */
void	print_message(char *str, t_philo *ph)
{
	pthread_mutex_lock(&ph->data->print);
	if (!is_end(ph))
		printf("%ld %d %s\n", get_time() - ph->data->t_of_start, ph->id, str);
	pthread_mutex_unlock(&ph->data->print);
}

/* Returns current time in miliseconds since the Epoch */
long int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/* Convert a char *str to an int */
int	simple_atoi(char *nptr)
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	if (ft_strlen(nptr) > 9)
		return (-1);
	while (nptr[++i])
		result = result * 10 + (nptr[i] - '0');
	return (result);
}

/* Allocate memory for nitems * size and set to '\0' */
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nitems * size);
	if (!ptr)
		return (0);
	memset(ptr, '\0', nitems * size);
	return (ptr);
}

// void	print_philos(t_philo *philos)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < philos->data->nbr_philos)
// 	{
// 		printf("Philosopher ID: %d\n", philos[i].id);
// 		printf("Number of meals: %d\n", philos[i].nbr_meals);
// 		printf("Time to die: %ld\n", philos[i].full_t_die);
// 		printf("Address of left fork %d: %p\n", i, (void *)(philos[i].l_fork));
// 		printf("Address of right fork %d: %p\n", i, (void *)(philos[i].r_fork));
// 		printf("\n");
// 	}
// }

/* Testing function to print contents of t_data */
// void	print_data(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	printf("Number of philosophers: %d\n", data->nbr_philos);
// 	printf("Time to die: %d\n", data->t_die);
// 	printf("Time to eat: %d\n", data->t_eat);
// 	printf("Time to sleep: %d\n", data->t_sleep);
// 	printf("Number of times each philosopher must eat: %d\n", data->nbr_t_eat);
// 	printf("Finished philosophers: %d\n", data->finished_philos);
// 	printf("Time of start: %ld\n", data->t_of_start);
// 	while (++i < data->nbr_philos)
// 		printf("Address of fork %d: %p\n", i, &(data->forks[i]));
// 	printf("\n");
// 	print_philos(data->philos);
// }
