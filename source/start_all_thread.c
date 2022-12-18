/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_all_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/18 12:49:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	start_all_thread(t_l_p *list_main)
{
	int		i;
	int		ret;
	t_ll_p	*copy;

	i = 0;
	copy = list_main->linked_list_philo;
	while (i < list_main->number_of_philosophers && copy)
	{
		ret = pthread_create(
				&copy->the_philosopher, NULL, exec_philo, (void *) copy);
		if (ret)
		{
			ft_putstr_fd("Error : thread no created\n", 2);
			return (1);
		}
		i++;
		copy = copy->next;
	}
	return (0);
}
