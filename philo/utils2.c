/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:57:52 by damachad          #+#    #+#             */
/*   Updated: 2024/01/15 11:30:02 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Returns 1 if c is a digit and 0 if it is not */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* Returns true if all strs only have digits */
bool	is_all_digit(char **strs)
{
	int	i;
	int	j;

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

void	*one_philo(t_philo *philo)
{
	print_message(FORK, philo);
	usleep(philo->data->t_die * 1000 + 100);
	print_message(DIE, philo);
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
