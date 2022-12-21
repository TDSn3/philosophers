/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:33:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/21 22:42:11 by tda-silv         ###   ########.fr       */
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



	usleep(1000);
	while (1)
	{
		copy = list_main.linked_list_philo;
		while (copy)
		{
			if (check_die(copy))
				break ;
			copy = copy->next;
		}
		if (!list_main.all_alives)
			break ;
		copy = list_main.linked_list_philo;
		usleep(1000);
	}
	wait_thread(&list_main);
	return (free_all(0, &list_main));
}
