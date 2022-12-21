/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:00:15 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/21 23:41:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	print_philo(t_ll_p *__, t_print status)
{
	__->err = pthread_mutex_lock(&__->list_main->mutex_start);
	if (__->err)
		return ((long int) return_error(1, __->err, 1));
	if (__->list_main->all_alives == 0)
	{
		__->err = pthread_mutex_unlock(&__->list_main->mutex_start);
		if (__->err)
			return ((long int) return_error(2, __->err, 1));
		return (2);
	}
//	__->err = pthread_mutex_unlock(&__->list_main->mutex_start);
//	if (__->err)
//		return ((long int) return_error(2, __->err, 0));




	if (get_time(__->list_main, &__->time))
		return (1);
	if (status == FORK1)
		printf("\033[32;02m%-5llu %-5d has taken a fork\033[00m\n",
			__->time, __->id);
	if (status == FORK2)
	{
		printf("\033[32m%-5llu %-5d has taken a fork\033[00m\n",
			__->time, __->id);
		printf("\033[34m%-5llu %-5d is eating\033[00m\n",
			__->time, __->id);
	}
	if (status == SLEEPING)
		printf("\033[36m%-5llu %-5d is sleeping\033[00m\n",
			__->time, __->id);
	if (status == THINKING)
		printf("\033[35m%-5llu %-5d is thinking\033[00m\n",
			__->time, __->id);
	if (status == DIED)
	{
		printf("\033[31;01m%-5llu %-5d died\033[00m\n",
			__->time, __->id);
		__->list_main->all_alives = 0;
	}
/*
	if (status == FORK1)
		printf("%llu %d has taken a fork\n",
			__->time, __->id);
	if (status == FORK2)
		printf("%llu %d has taken a fork\n",
			__->time, __->id);
	if (status == EATING)
		printf("%llu %d is eating\n",
			__->time, __->id);
	if (status == SLEEPING)
		printf("%llu %d is sleeping\n",
			__->time, __->id);
	if (status == THINKING)
		printf("%llu %d is thinking\n",
			__->time, __->id);
	if (status == DIED)
		printf("%llu %d died\n",
			__->time, __->id);*/
	__->err = pthread_mutex_unlock(&__->list_main->mutex_start);
	if (__->err)
		return ((long int) return_error(2, __->err, 0));
	return (0);
}
