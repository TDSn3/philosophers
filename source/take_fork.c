/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:06:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/19 01:17:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	on_next_list(t_l_p *list_main, t_ll_p *own_ll_p, int *eat);
static int	on_first_list(t_l_p *list_main, t_ll_p *own_ll_p, int *eat);
static int	return_error(void);

int	take_fork(t_l_p *list_main, t_ll_p *own_ll_p, int *eat)
{
	if (own_ll_p->next)
	{
		if (on_next_list(list_main, own_ll_p, eat))
			return (1);
	}
	else
	{
		if (on_first_list(list_main, own_ll_p, eat))
			return (1);
	}
	return (0);
}

static int	on_next_list(t_l_p *list_main, t_ll_p *own_ll_p, int *eat)
{
	struct timeval		tv;
	unsigned long int	time;
	int					err;

	gettimeofday(&tv, NULL);
	time = (tv.tv_usec - list_main->timestamp) / 1000;
	err = pthread_mutex_lock(&own_ll_p->next->mutex_fork);
	if (err)
		return (return_error());
	own_ll_p->next->fork = 1;
	printf("\033[32m%-5lu %-5d has taken a fork\033[00m\n", time, own_ll_p->id);
	printf("\033[34m%-5lu %-5d is eating\033[00m\n", time, own_ll_p->id);
	usleep(list_main->time_to_eat * 1000);
	gettimeofday(&tv, NULL);
	*eat = (tv.tv_usec - list_main->timestamp) / 1000;
	err = pthread_mutex_unlock(&own_ll_p->next->mutex_fork);
	if (err)
		return (return_error());
	return (0);
}

static int	on_first_list(t_l_p *list_main, t_ll_p *own_ll_p, int *eat)
{
	struct timeval		tv;
	unsigned long int	time;
	int					err;

	gettimeofday(&tv, NULL);
	time = (tv.tv_usec - list_main->timestamp) / 1000;
	err = pthread_mutex_lock(&list_main->linked_list_philo->mutex_fork);
	if (err)
		return (return_error());
	own_ll_p->prev->fork = 1;
	printf("\033[32m%-5lu %-5d has taken a fork\033[00m\n", time, own_ll_p->id);
	printf("\033[34m%-5lu %-5d is eating\033[00m\n", time, own_ll_p->id);
	usleep(list_main->time_to_eat * 1000);
	gettimeofday(&tv, NULL);
	*eat = (tv.tv_usec - list_main->timestamp) / 1000;
	err = pthread_mutex_unlock(&list_main->linked_list_philo->mutex_fork);
	if (err)
		return (return_error());
	return (0);
}

static int	return_error(void)
{
	ft_putstr_fd("Error : pthread_mutex_lock\n", 2);
	return (1);
}
