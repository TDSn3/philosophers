/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:59:56 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/23 20:45:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	print_died(t_ll_p *__);
static int	add_one_end_eat(t_ll_p *__);

int	check_die(t_ll_p *__)
{
	unsigned long long int	time;
	int						err;

	if (get_time(__->list_main, &time))
		return (1);
	err = pthread_mutex_lock(&__->mutex_eat);
	if (err)
		return ((long int) return_error(1, err, 1));
	if (time >= (unsigned long long int) __->eat && time - __->eat
		>= (unsigned long long int) __->list_main->time_to_die)
		return (print_died(__));
	if (__->list_main->argc == 6 && *__->total_eat
		>= __->list_main->number_of_times_each_philosopher_must_eat)
		return (add_one_end_eat(__));
	err = pthread_mutex_unlock(&__->mutex_eat);
	if (err)
		return ((long int) return_error(2, err, 1));
	return (0);
}

static int	add_one_end_eat(t_ll_p *__)
{
	int	err;

	err = pthread_mutex_unlock(&__->mutex_eat);
	if (err)
		return ((long int) return_error(2, err, 1));
	__->list_main->end_eat += 1;
	return (0);
}

static int	print_died(t_ll_p *__)
{
	int	err;

	err = pthread_mutex_unlock(&__->mutex_eat);
	if (err)
		return ((long int) return_error(2, err, 1));
	print_philo(__, DIED);
	return (1);
}
