/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:59:56 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/20 20:17:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	check_die(t_l_p *list_main, t_ll_p *own_ll_p, int eat, t_l_ep *__)
{
	int					err;
//	struct timeval		tv;

	if (list_main->all_alives == 0)
		return (1);
//	if (gettimeofday(&tv, NULL))
//		return ((long int) return_error(3, errno, 1));
//	__->time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
//		- list_main->timestamp - eat;
	if (__->time >= (unsigned long long int) list_main->time_to_die)
	{
		err = pthread_mutex_lock(&list_main->mutex_start);
		if (err)
			return ((long int) return_error(1, err, 1));
		list_main->all_alives = 0;
		err = pthread_mutex_unlock(&list_main->mutex_start);
		if (err)
			return ((long int) return_error(2, err, 1));
//		printf("time = %llu\n", __->time + eat);
//		printf("time to die = %llu\n", (unsigned long long int) list_main->time_to_die);
//		printf("eat = %d\n", eat);
//		printf("time - eat = %lld\n", __->time);
		printf("\033[31;01m%-5u %-5d died\033[00m\n",
			eat + list_main->time_to_die, own_ll_p->id);
		own_ll_p->alive = 0;
		list_main->all_alives = 0;
		return (1);
	}
	return (0);
}

int	check_die2(t_l_p *list_main, t_ll_p *own_ll_p, int eat, t_l_ep *__)
{
	int					err;
	struct timeval		tv;
	unsigned long int	time;

	if (list_main->all_alives == 0)
		return (1);
	if (gettimeofday(&tv, NULL))
		return ((long int) return_error(3, errno, 1));
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
		- list_main->timestamp - eat;
	if (time >= (unsigned long long int) list_main->time_to_die)
	{
		err = pthread_mutex_lock(&list_main->mutex_start);
		if (err)
			return ((long int) return_error(1, err, 1));
		list_main->all_alives = 0;
		err = pthread_mutex_unlock(&list_main->mutex_start);
		if (err)
			return ((long int) return_error(2, err, 1));
		printf("time = %llu\n", __->time + eat);
		printf("time to die = %llu\n", (unsigned long long int) list_main->time_to_die);
		printf("eat = %d\n", eat);
		printf("time - eat = %lld\n", __->time - eat);
		time = __->time + (list_main->time_to_die - eat);
		printf("\033[31;01m%-5lu %-5d 2died\033[00m\n", time + eat, own_ll_p->id);
		own_ll_p->alive = 0;
		return (1);
	}
	return (0);
}
