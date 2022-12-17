/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:21:12 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 00:25:12 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	ft_atoi(const char *nptr);

int	init(t_philo *philo, int argc, char **argv)
{
	philo->number_of_philosophers = ft_atoi(argv[1]);
	if (philo->number_of_philosophers > PTHREAD_KEYS_MAX)
		return (1);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	memset(philo->the_philosophers, 0, sizeof(pthread_t) * PTHREAD_KEYS_MAX);
	return (0);
}

static int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	nb;
	long long int	final_nb;
	int				if_is_negative;

	i = 0;
	nb = 0;
	if_is_negative = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			if_is_negative = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	return (final_nb = nb * if_is_negative);
}
