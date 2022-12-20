/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:33:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/20 20:47:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

/* ************************************************************************** */
/*                                                                            */
/*   2 number_of_philosophers												  */
/*   3 time_to_die															  */
/*   4 time_to_eat															  */
/*   5 time_to_sleep														  */
/*   6 number_of_times_each_philosopher_must_eat (argument optionnel)		  */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_l_p			list_main;
	t_ll_p			*copy;

	if (check_error(argc, argv) || init(&list_main, argc, argv)
		|| start_all_thread(&list_main))
		return (1);




	struct timeval		tv;

	while (list_main.start < list_main.number_of_philosophers)
		usleep(50);
	while (1)
	{
		copy = list_main.linked_list_philo;
		if (gettimeofday(&tv, NULL))
			return ((long int) return_error(3, errno, 1));
		copy->__->time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
			- copy->list_main->timestamp - copy->__->eat;
		while (copy)
		{
			if (check_die(&list_main, copy, copy->__->eat, copy->__))
				break ;
			copy = copy->next;
		}
		if (!list_main.all_alives)
			break ;
		copy = list_main.linked_list_philo;
		usleep(1000);
	}
//	wait_thread(&list_main);
	return (free_all(0, &list_main));
}
