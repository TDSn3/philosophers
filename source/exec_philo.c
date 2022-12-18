/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/18 07:56:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	*exec_philo(void *data)
{
	t_ll_p			*own_ll_p;
	t_l_p			*list_main;
	struct timeval	tv;
	unsigned int	time;

	own_ll_p = (t_ll_p *) data;
	list_main = own_ll_p->list_main;
	gettimeofday(&tv, NULL);
	time = (tv.tv_usec - list_main->timestamp) / 1000;
	printf("%-5d %d created\n", time, own_ll_p->id);
	list_main->start += 1;
	while (1)
	{
		if (list_main->start < list_main->number_of_philosophers)
			usleep(1000);
		else
			break ;
	}
	while (1)
	{
		gettimeofday(&tv, NULL);
		time = (tv.tv_usec - list_main->timestamp) / 1000;
		if ((int) time >= list_main->time_to_die)
		{
			printf("%-5d %d died\n", time, own_ll_p->id);
			return (NULL);
		}
	}
	return (NULL);
}
