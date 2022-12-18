/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/18 16:09:29 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	wait_all_exec(t_l_p *list_main);

void	*exec_philo(void *data)
{
	t_ll_p			*own_ll_p;
	t_l_p			*list_main;
	struct timeval	tv;
	int				time;
	int				eaten;
	int				err;

	own_ll_p = (t_ll_p *) data;
	if (!own_ll_p->alive)
		return (NULL);
	list_main = own_ll_p->list_main;
	gettimeofday(&tv, NULL);
	time = (tv.tv_usec - list_main->timestamp) / 1000;
	eaten = 0;
	printf("%-5u %-5d created\n", time, own_ll_p->id);
	if (wait_all_exec(list_main))
		return (NULL);



	while (1)
	{
		err = pthread_mutex_lock(&list_main->mutex);
		if (err)
		{
			ft_putstr_fd("Error : pthread_mutex_lock\n", 2);
			return (NULL);
		}
		gettimeofday(&tv, NULL);
		time = (tv.tv_usec - list_main->timestamp) / 1000;
		own_ll_p->fork = 1;
		printf("%-5u %-5d has taken own fork\n", time, own_ll_p->id);
		if (own_ll_p->next)
			own_ll_p->next->fork = 1;
		else
			list_main->linked_list_philo->fork = 1;
		usleep(list_main->time_to_eat * 1000);
		printf("%-5u %-5d has taken right fork\n", time, own_ll_p->id);
		err = pthread_mutex_unlock(&list_main->mutex);
		if (err)
		{
			ft_putstr_fd("Error : pthread_mutex_unlock\n", 2);
			return (NULL);
		}



		gettimeofday(&tv, NULL);
		time = ((tv.tv_usec + eaten) - list_main->timestamp) / 1000;
		if (time >= list_main->time_to_die)
		{
			printf("%-5d %-5d died\n", time, own_ll_p->id);
			own_ll_p->alive = 0;
			return (NULL);
		}
	}
	return (NULL);
}

static int	wait_all_exec(t_l_p *list_main)
{
	int	err;

	err = pthread_mutex_lock(&list_main->mutex);
	if (err)
	{
		ft_putstr_fd("Error : pthread_mutex_lock\n", 2);
		return (1);
	}
	list_main->start += 1;
	err = pthread_mutex_unlock(&list_main->mutex);
	if (err)
	{
		ft_putstr_fd("Error : pthread_mutex_unlock\n", 2);
		return (1);
	}
	while (list_main->start < list_main->number_of_philosophers)
		usleep(1000);
	return (0);
}
