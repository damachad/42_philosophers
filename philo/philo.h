/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:15:11 by damachad          #+#    #+#             */
/*   Updated: 2023/12/12 16:48:41 by damachad         ###   ########.fr       */
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
# include <sys/time.h>

// Macros

# define ERROR_ARGS "Usage: ./philo nbr_philos t_die t_eat t_sleep [nbr_times_each_must_eat]\n"

// Structures



// Prototypes

int	ft_atoi(char *nptr);

#endif
