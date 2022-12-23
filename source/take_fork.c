/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:06:14 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/23 01:29:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	on_next_list(t_ll_p *__, pthread_mutex_t *mutex_fork);
static int	on_first_list(t_ll_p *__, pthread_mutex_t *mutex_fork);

int	take_fork(t_ll_p *__)
{
	if (__->next)
	{
		if (on_next_list(__, &__->next->mutex_fork))
			return (1);
	}
	else
	{
		if (on_first_list(__, &__->list_main->linked_list_philo->mutex_fork))
			return (1);
	}
	return (0);
}

static int	on_next_list(t_ll_p *__, pthread_mutex_t *mutex_fork)
{
	__->err = pthread_mutex_lock(mutex_fork);
	if (__->err)
		return ((long int) return_error(1, __->err, 1));
	__->next->fork = 1;
	if (print_philo(__, FORK2))
		return (1);
	my_usleep(__->list_main, __->list_main->time_to_eat);

	if (__->err)
		return ((long int) return_error(1, __->err, 1));
	if (get_time(__->list_main, (unsigned long long int *) &__->eat))
		return (1);
	__->total_eat += 1;
	__->err = pthread_mutex_unlock(&__->mutex_eat);
	if (__->err)
		return ((long int) return_error(2, __->err, 1));

	__->err = pthread_mutex_unlock(mutex_fork);
	if (__->err)
		return ((long int) return_error(2, __->err, 1));
	return (0);
}

static int	on_first_list(t_ll_p *__, pthread_mutex_t *mutex_fork)
{
	if (__ == __->list_main->linked_list_philo)
		return (0);
	__->err = pthread_mutex_lock(mutex_fork);
	if (__->err)
		return ((long int) return_error(1, __->err, 1));
	__->prev->fork = 1;
	if (print_philo(__, FORK2))
		return (1);
	my_usleep(__->list_main, __->list_main->time_to_eat);

	if (__->err)
		return ((long int) return_error(1, __->err, 1));
	if (get_time(__->list_main, (unsigned long long int *) &__->eat))
		return (1);
	__->total_eat += 1;
	__->err = pthread_mutex_unlock(&__->mutex_eat);
	if (__->err)
		return ((long int) return_error(2, __->err, 1));

	__->err = pthread_mutex_unlock(mutex_fork);
	if (__->err)
		return ((long int) return_error(2, __->err, 1));
	return (0);
}
