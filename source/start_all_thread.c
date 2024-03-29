/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_all_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/21 22:44:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	exec_all_thread(t_l_p *list_main);

int	start_all_thread(t_l_p *list_main)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	list_main->timestamp = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	if (exec_all_thread(list_main))
		return (1);
	return (0);
}

int	exec_all_thread(t_l_p *list_main)
{
	int		i;
	int		err;
	t_ll_p	*copy;

	i = 0;
	copy = list_main->linked_list_philo;
	while (i < list_main->number_of_philosophers && copy)
	{
		err = pthread_create(
				&copy->the_philosopher, NULL, exec_philo, (void *) copy);
		if (err)
		{
			ft_putstr_fd("Error : thread no created\n", 2);
			return (1);
		}
		i++;
		copy = copy->next;
	}
	return (0);
}
