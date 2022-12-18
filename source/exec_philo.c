/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/18 12:57:19 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	*exec_philo(void *data)
{
	t_ll_p			*own_ll_p;
	t_l_p			*list_main;
	struct timeval	tv;
	int				time;
	int				err;

	own_ll_p = (t_ll_p *) data;
	if (!own_ll_p->alive)
		return (NULL);
	list_main = own_ll_p->list_main;
	gettimeofday(&tv, NULL);
	time = (tv.tv_usec - list_main->timestamp) / 1000;
	if (time < 0)
		time = 0;
//	printf("%-5u %d created\n", time, own_ll_p->id);



	err = pthread_mutex_lock(&list_main->mutex);
	if (err)
	{
		ft_putstr_fd("Error : pthread_mutex_lock\n", 2);
		return (NULL);
	}
	if (list_main->start < list_main->number_of_philosophers)
	{
		list_main->start += 1;
		err = pthread_mutex_unlock(&list_main->mutex);
		if (err)
			ft_putstr_fd("Error : pthread_mutex_unlock\n", 2);
		return (NULL);
	}
	err = pthread_mutex_unlock(&list_main->mutex);
	if (err)
	{
		ft_putstr_fd("Error : pthread_mutex_unlock\n", 2);
		return (NULL);
	}



	gettimeofday(&tv, NULL);
	time = (tv.tv_usec - list_main->timestamp) / 1000;
	if (time >= list_main->time_to_die)
	{
		printf("%-5d %d died\n", time, own_ll_p->id);
		own_ll_p->alive = 0;
	}
	return (NULL);
}
