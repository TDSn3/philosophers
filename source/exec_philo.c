/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 01:18:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	*exec_philo(void *data)
{
	long int	num_philo;

	num_philo = (long int) data;
	printf("Phhilosopher %ld created\n", num_philo + 1);
	return (NULL);
}
