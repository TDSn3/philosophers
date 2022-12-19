/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_all_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/19 01:02:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	exec_all_thread(t_l_p *list_main);

int	start_all_thread(t_l_p *list_main)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	list_main->timestamp = tv.tv_usec;
	if (exec_all_thread(list_main))
		return (1);
	return (0);
}

int	exec_all_thread(t_l_p *list_main)
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
