/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:59:56 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/22 13:18:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	check_die(t_ll_p *__)
{
	unsigned long long int	time;

	if (get_time(__->list_main, &time))
		return (1);
	__->err = pthread_mutex_lock(&__->mutex_eat);
	if (__->err)
		return ((long int) return_error(1, __->err, 1));
	if (time >= (unsigned long long int) __->eat
		&& time - __->eat
		>= (unsigned long long int) __->list_main->time_to_die)
	{
		__->err = pthread_mutex_unlock(&__->mutex_eat);
		if (__->err)
			return ((long int) return_error(2, __->err, 1));
		print_philo(__, DIED);
		__->alive = 0;
		return (1);
	}
	__->err = pthread_mutex_unlock(&__->mutex_eat);
	if (__->err)
		return ((long int) return_error(2, __->err, 1));
	return (0);
}
