/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:06:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/20 20:35:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	on_next_list(t_l_p *list_main, t_ll_p *own_ll_p, int *eat, t_l_ep *__);
static int	on_first_list(t_l_p *list_main, t_ll_p *own_ll_p, int *eat, t_l_ep *__);

int	take_fork(t_l_p *list_main, t_ll_p *own_ll_p, int *eat, t_l_ep	*__)
{
	if (own_ll_p->next)
	{
		if (on_next_list(list_main, own_ll_p, eat, __))
			return (1);
	}
	else
	{
		if (on_first_list(list_main, own_ll_p, eat, __))
			return (1);
	}
	return (0);
}

static int	on_next_list(t_l_p *list_main, t_ll_p *own_ll_p, int *eat, t_l_ep *__)
{
	struct timeval		tv;
	unsigned long int	time;
	int					err;

	err = pthread_mutex_lock(&own_ll_p->next->mutex_fork);
	if (err)
		return ((long int) return_error(1, err, 1));
	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - list_main->timestamp;
	own_ll_p->next->fork = 1;
	if (!list_main->all_alives)
		return (1);
	printf("\033[32m%-5lu %-5d has taken a fork\033[00m\n", time, own_ll_p->id);
	printf("\033[34m%-5lu %-5d is eating\033[00m\n", time, own_ll_p->id);
	usleep(list_main->time_to_eat * 1000);
	if (!__->list_main->all_alives)
		return (1);
	gettimeofday(&tv, NULL);
	*eat = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - list_main->timestamp;
	err = pthread_mutex_unlock(&own_ll_p->next->mutex_fork);
	if (err)
		return ((long int) return_error(2, err, 1));
	return (0);
}

static int	on_first_list(t_l_p *list_main, t_ll_p *own_ll_p, int *eat, t_l_ep *__)
{
	struct timeval		tv;
	unsigned long int	time;
	int					err;

	if (own_ll_p == list_main->linked_list_philo)
		return (0);
	err = pthread_mutex_lock(&list_main->linked_list_philo->mutex_fork);
	if (err)
		return ((long int) return_error(1, err, 1));
	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - list_main->timestamp;
	own_ll_p->prev->fork = 1;
	if (!list_main->all_alives)
		return (1);
	printf("\033[32m%-5lu %-5d has taken a fork\033[00m\n", time, own_ll_p->id);
	printf("\033[34m%-5lu %-5d is eating\033[00m\n", time, own_ll_p->id);
	usleep(list_main->time_to_eat * 1000);
	if (!__->list_main->all_alives)
		return (1);
	gettimeofday(&tv, NULL);
	*eat = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - list_main->timestamp;
	err = pthread_mutex_unlock(&list_main->linked_list_philo->mutex_fork);
	if (err)
		return ((long int) return_error(2, err, 1));
	return (0);
}

