/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/19 01:16:43 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	wait_all_exec(t_l_p *list_main);
static int	check_die(t_l_p *list_main, t_ll_p *own_ll_p, int eat);

void	*exec_philo(void *data)
{
	t_ll_p				*own_ll_p;
	t_l_p				*list_main;
	struct timeval		tv;
	unsigned long int	time;
	int					eat;
	int					err;

	own_ll_p = (t_ll_p *) data;
	if (!own_ll_p->alive)
		return (NULL);
	list_main = own_ll_p->list_main;
	gettimeofday(&tv, NULL);
	time = (tv.tv_usec - list_main->timestamp) / 1000;
	eat = 0;
	printf("\033[30m%-5lu %-5d created\033[00m\n", time, own_ll_p->id);
	if (wait_all_exec(list_main))
		return (NULL);



	while (1)
	{
		err = pthread_mutex_lock(&own_ll_p->mutex_fork);
		if (err)
		{
			ft_putstr_fd("Error : pthread_mutex_lock\n", 2);
			return (NULL);
		}
		gettimeofday(&tv, NULL);
		time = (tv.tv_usec - list_main->timestamp) / 1000;
		own_ll_p->fork = 1;
		printf("\033[32;02m%-5lu %-5d has taken a fork\033[00m\n", time, own_ll_p->id);
		if (take_fork(list_main, own_ll_p, &eat))
			return (NULL);
		err = pthread_mutex_unlock(&own_ll_p->mutex_fork);
		if (err)
		{
			ft_putstr_fd("Error : pthread_mutex_unlock\n", 2);
			return (NULL);
		}



		gettimeofday(&tv, NULL);
		time = (tv.tv_usec - list_main->timestamp) / 1000;
		printf("\033[36m%-5lu %-5d is sleeping\033[00m\n", time, own_ll_p->id);
		while (1)
		{
			gettimeofday(&tv, NULL);
			time = ((tv.tv_usec - list_main->timestamp) / 1000 - eat);
			if (time >= (unsigned long int) list_main->time_to_die)
			{
				gettimeofday(&tv, NULL);
				time = (tv.tv_usec - list_main->timestamp) / 1000;
				printf("\033[31;01m%-5ld %-5d died\033[00m\n", time, own_ll_p->id);
				own_ll_p->alive = 0;
				return (NULL);
			}
			if (time >= (unsigned long int) list_main->time_to_sleep)
				break ;
		}
		gettimeofday(&tv, NULL);
		time = (tv.tv_usec - list_main->timestamp) / 1000;
		printf("\033[36;02m%-5ld %-5d wakes up\033[00m\n", time, own_ll_p->id);

		if (check_die(list_main, own_ll_p, eat))
			return (NULL);
	}
	return (NULL);
}

static int	check_die(t_l_p *list_main, t_ll_p *own_ll_p, int eat)
{
	struct timeval		tv;
	unsigned long int	time;

	if (gettimeofday(&tv, NULL))
	{
		ft_putstr_fd("Error : gettimeofday\n", 2);
		return (1);
	}
	time = ((tv.tv_usec - list_main->timestamp) / 1000) - eat;
	if (time >= (unsigned long int) list_main->time_to_die)
	{
		gettimeofday(&tv, NULL);
		time = (tv.tv_usec - list_main->timestamp) / 1000;
		printf("\033[31;01m%-5lu %-5d died\033[00m\n", time, own_ll_p->id);
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
	{
		ft_putstr_fd("Error : pthread_mutex_lock\n", 2);
		return (1);
	}
	list_main->start += 1;
	err = pthread_mutex_unlock(&list_main->mutex_start);
	if (err)
	{
		ft_putstr_fd("Error : pthread_mutex_unlock\n", 2);
		return (1);
	}
	while (list_main->start < list_main->number_of_philosophers)
		usleep(1000);
	return (0);
}

