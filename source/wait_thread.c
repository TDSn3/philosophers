/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:14:12 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/23 20:52:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	wait_thread(t_l_p *list_main)
{
	int		i;
	t_ll_p	*copy;

	i = 0;
	copy = (t_ll_p *)list_main->linked_list_philo;
	while (i < list_main->number_of_philosophers && copy)
	{
		pthread_join (copy->the_philosopher, NULL);
		i++;
		copy = copy->next;
		usleep(1000);
	}
}
