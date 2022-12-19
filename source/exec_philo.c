/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/19 11:33:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	init_list(t_l_ep *list, void *data);
static int	wait_all_exec(t_l_p *list_main);
static int	check_die(t_l_p *list_main, t_ll_p *own_ll_p, int eat);

void	*exec_philo(void *data)
{
	t_l_ep	__;

	init_list(&__, data);
	printf("\033[30m%-5llu %-5d created\033[00m\n", __.time, __.own_ll_p->id);
	if (wait_all_exec(__.list_main))
		return (NULL);



	while (1)
	{
		__.err = pthread_mutex_lock(&__.own_ll_p->mutex_fork);
		if (__.err)
			return (return_error(1, __.err, 0));
		if (gettimeofday(&__.tv, NULL))
			return (return_error(3, errno, 1));
		__.time = ((__.tv.tv_sec * 1000) + (__.tv.tv_usec / 1000)) - __.list_main->timestamp;
		__.own_ll_p->fork = 1;
		printf("\033[32;02m%-5llu %-5d has taken a fork\033[00m\n", __.time, __.own_ll_p->id);
		if (take_fork(__.list_main, __.own_ll_p, &__.eat))
			return (NULL);
		__.err = pthread_mutex_unlock(&__.own_ll_p->mutex_fork);
		if (__.err)
			return (return_error(2, __.err, 0));



		if (gettimeofday(&__.tv, NULL))
			return (return_error(3, errno, 1));
		__.time = ((__.tv.tv_sec * 1000) + (__.tv.tv_usec / 1000)) - __.list_main->timestamp;
		printf("\033[36m%-5llu %-5d is sleeping\033[00m\n", __.time, __.own_ll_p->id);
		while (1)
		{
			if (gettimeofday(&__.tv, NULL))
				return (return_error(3, errno, 1));
			__.time = ((__.tv.tv_sec * 1000) + (__.tv.tv_usec / 1000)) - __.list_main->timestamp - __.eat;
			if (__.time >= (unsigned long long int) __.list_main->time_to_die)
			{
				printf("\033[31;01m%-5llu %-5d died\033[00m\n", __.time + __.eat, __.own_ll_p->id);
				__.own_ll_p->alive = 0;
				return (NULL);
			}
			if (__.time >= (unsigned long long int) __.list_main->time_to_sleep)
				break ;
		}
		if (gettimeofday(&__.tv, NULL))
			return (return_error(3, errno, 1));
		__.time = ((__.tv.tv_sec * 1000) + (__.tv.tv_usec / 1000)) - __.list_main->timestamp;
		printf("\033[36;02m%-5llu %-5d wakes up\033[00m\n", __.time, __.own_ll_p->id);

		if (check_die(__.list_main, __.own_ll_p, __.eat))
			return (NULL);
	}
	return (NULL);
}

static int	check_die(t_l_p *list_main, t_ll_p *own_ll_p, int eat)
{
	struct timeval		tv;
	unsigned long int	time;

	if (gettimeofday(&tv, NULL))
		return ((long int) return_error(3, errno, 1));
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
		- list_main->timestamp - eat;
	if (time >= (unsigned long long int) list_main->time_to_die)
	{
		printf("\033[31;01m%-5lu %-5d died\033[00m\n", time - eat, own_ll_p->id);
		own_ll_p->alive = 0;
		return (1);
	}
	return (0);
}

static int	wait_all_exec(t_l_p *list_main)
{
	int	err;

	err = pthread_mutex_lock(&list_main->mutex_start);
	if (err)
		return ((long int) return_error(1, err, 1));
	list_main->start += 1;
	err = pthread_mutex_unlock(&list_main->mutex_start);
	if (err)
		return ((long int) return_error(2, err, 1));
	while (list_main->start < list_main->number_of_philosophers)
		usleep(50);
	return (0);
}

static int	init_list(t_l_ep *list, void *data)
{
	list->own_ll_p = (t_ll_p *) data;
	if (!list->own_ll_p->alive)
		return (1);
	list->list_main = list->own_ll_p->list_main;
	if (gettimeofday(&list->tv, NULL))
		return ((long int) return_error(3, errno, 1));
	list->time = ((list->tv.tv_sec * 1000) + (list->tv.tv_usec / 1000))
		- list->list_main->timestamp;
	list->eat = 0;
	return (0);
}
