/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:33:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/23 20:33:20 by tda-silv         ###   ########.fr       */
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

static void	supervisor(t_l_p *list_main);

int	main(int argc, char **argv)
{
	t_l_p	list_main;

	memset(&list_main, 0, sizeof(t_l_p));
	if (check_error(argc, argv) || init(&list_main, argc, argv)
		|| start_all_thread(&list_main))
		return (1);
	supervisor(&list_main);
	wait_thread(&list_main);
	return (free_all(0, &list_main));
}

static void	supervisor(t_l_p *list_main)
{
	t_ll_p	*copy;

	usleep((list_main->time_to_die * 1000) - 1000);
	while (1)
	{
		copy = list_main->linked_list_philo;
		while (copy)
		{
			if (check_die(copy) || list_main->end_eat
				>= list_main->number_of_philosophers)
				break ;
			copy = copy->next;
		}
		if (!list_main->all_alives || list_main->end_eat
			>= list_main->number_of_philosophers)
			break ;
		copy = list_main->linked_list_philo;
		usleep(1000);
	}
}
