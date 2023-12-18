/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:11 by damachad          #+#    #+#             */
/*   Updated: 2023/12/18 11:37:40 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// Includes

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>

// Macros

# define ERROR_ARGS "Usage: ./philo nbr_philos t_die t_eat t_sleep [nbr_times_each_must_eat]\n"

// Structures

typedef struct philo
{
	struct s_data	*data;
	int				id;
	int				last_meal;
	int				nbr_meals;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}					t_philo;

typedef struct	s_data
{
	int					nbr_philos;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					nbr_times_each_must_eat;
	bool				dead_philo;
	t_philo				*philos;
	pthread_t			*seats;
	pthread_t			monitor;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
}						t_data;

// Prototypes

// In init.c
int		seat_philos(t_data *data);
int		init_data(t_data *data, char **argv);

// In utils.c
int		get_time(void);
int		ft_atoi(char *nptr);
void	*ft_calloc(size_t nitems, size_t size);

// In routine.c
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);

#endif
