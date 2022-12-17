/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:33:37 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 01:25:21 by tda-silv         ###   ########.fr       */
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
	t_philo	philo;

	if (check_error(argc, argv) || init(&philo, argc, argv))
		return (1);
	start_all_thread(&philo);
	wait_pt(&philo);
	return (0);
}
