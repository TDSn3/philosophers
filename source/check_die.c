/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:59:56 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/19 22:24:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	check_die(t_l_p *list_main, t_ll_p *own_ll_p, int eat, t_l_ep *__)
{
	struct timeval		tv;

	if (gettimeofday(&tv, NULL))
		return ((long int) return_error(3, errno, 1));
	__->time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
		- list_main->timestamp - eat;
	if (__->time >= (unsigned long long int) list_main->time_to_die)
	{
		printf("\033[31;01m%-5llu %-5d died\033[00m\n",
			__->time - eat, own_ll_p->id);
		own_ll_p->alive = 0;
		return (1);
	}
	return (0);
}

int	check_die2(t_l_p *list_main, t_ll_p *own_ll_p, int eat, t_l_ep *__)
{
	struct timeval		tv;
	unsigned long int	time;

	if (gettimeofday(&tv, NULL))
		return ((long int) return_error(3, errno, 1));
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
		- list_main->timestamp - eat;
	if (time >= (unsigned long long int) list_main->time_to_die)
	{
		time = __->time + (list_main->time_to_die - eat);
		printf("\033[31;01m%-5lu %-5d died\033[00m\n", time - eat, own_ll_p->id);
		own_ll_p->alive = 0;
		return (1);
	}
	return (0);
}
