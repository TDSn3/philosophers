/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/20 20:35:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	init_list(t_l_ep *list, void *data);
static int	wait_all_exec(t_l_p *list_main);
static int	take_first_fork(t_l_ep	*__);
static int	philo_sleep(t_l_ep	*__);

void	*exec_philo(void *data)
{
	t_l_ep	__;

	init_list(&__, data);
	printf("\033[30m%-5llu %-5d created\033[00m\n", __.time, __.own_ll_p->id);
	if (wait_all_exec(__.list_main))
		return (NULL);
	while (1)
	{
		if (!__.list_main->all_alives
			|| take_first_fork(&__)
			|| philo_sleep(&__))
			return (NULL);
		if (__.time < (unsigned long long int)__.list_main->time_to_die)
		{
			printf("\033[35m%-5llu %-5d is thinking\033[00m\n",
				__.time + __.eat, __.own_ll_p->id);
			if (__.list_main->time_to_die - __.time > 5)
				usleep(((__.list_main->time_to_die - __.time) * 1000) / 1.1);
		}
	}
	return (NULL);
}

static int	take_first_fork(t_l_ep	*__)
{
	__->err = pthread_mutex_lock(&__->own_ll_p->mutex_fork);
	if (__->err)
		return ((long int) return_error(1, __->err, 1));
	__->time += __->eat;
	__->own_ll_p->fork = 1;
	printf("\033[32;02m%-5llu %-5d has taken a fork\033[00m\n",
		__->time, __->own_ll_p->id);
	if (take_fork(__->list_main, __->own_ll_p, &__->eat, __))
	{
		__->err = pthread_mutex_unlock(&__->own_ll_p->mutex_fork);
		if (__->err)
			return_error(2, __->err, 0);
		return (1);
	}
	__->err = pthread_mutex_unlock(&__->own_ll_p->mutex_fork);
	if (__->err)
		return ((long int) return_error(2, __->err, 1));
	return (0);
}

static int	philo_sleep(t_l_ep	*__)
{
	if (__->list_main->all_alives == 0)
		return (1);
	if (gettimeofday(&__->tv, NULL))
	{
		return_error(3, errno, 1);
		return (1);
	}
	__->time = ((__->tv.tv_sec * 1000) + (__->tv.tv_usec / 1000))
		- __->list_main->timestamp;
	printf("\033[36m%-5llu %-5d is sleeping\033[00m\n",
		__->time, __->own_ll_p->id);
	usleep(__->list_main->time_to_sleep * 1000);
	if (__->list_main->all_alives == 0)
		return (1);
	if (gettimeofday(&__->tv, NULL))
	{
		return_error(3, errno, 1);
		return (1);
	}
	__->time = ((__->tv.tv_sec * 1000) + (__->tv.tv_usec / 1000))
		- __->list_main->timestamp;
	printf("\033[36;02m%-5llu %-5d wakes up\033[00m\n",
		__->time, __->own_ll_p->id);
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
	list->own_ll_p->__ = list;
	return (0);
}
