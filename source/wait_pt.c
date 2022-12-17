/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:14:12 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 01:23:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	wait_pt(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
		pthread_join (philo->the_philosophers[i++], NULL);
}
