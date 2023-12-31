/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:11 by damachad          #+#    #+#             */
/*   Updated: 2023/12/31 11:20:40 by damachad         ###   ########.fr       */
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

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

// Structures

typedef struct philo
{
	struct s_data	*data;
	int				id;
	int				nbr_meals;
	long int		t_of_last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	lock;
	pthread_t		checker;
}					t_philo;

typedef struct	s_data
{
	int					nbr_philos;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					nbr_times_each_must_eat;
	int					finished_philos;
	long int			t_of_start;
	bool				dead_philo;
	t_philo				*philos;
	pthread_t			*seats;
	pthread_t			monitor;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_mutex_t		end;
}						t_data;

// Prototypes

// In init.c
int			seat_philos(t_data *data);
int			init_data(t_data **data, char **argv);

// In utils.c
void		ft_usleep(int time_in_us);
void		print_message(char *str, t_philo *philo);
void		print_end_message(char *str, t_philo *philo);
long int	get_time(void);
int			simple_atoi(char *nptr);
void		*ft_calloc(size_t nitems, size_t size);

void		print_data(t_data *data);

// In utils2.c
bool		is_all_digit(char **strs);
bool		is_end(t_philo *philo);
int			one_philo(t_data *data);

// In routine.c
void		*philo_routine(void *arg);
void		*monitor_routine(void *arg);

#endif
