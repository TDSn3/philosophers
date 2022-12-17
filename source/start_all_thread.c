/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_all_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 01:25:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	start_all_thread(t_philo *philo)
{
	long int	i;
	int			ret;

	i = 0;
	while (i < philo->number_of_philosophers)
	{
		ret = pthread_create(
				&philo->the_philosophers[i], NULL, exec_philo, (void *) i);
		if (ret)
		{
			printf("Error\n");
			continue ;
		}
		i++;
	}
	return (0);
}
