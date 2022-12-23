/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_first_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:31:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/23 14:11:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	on_next_list(t_ll_p *__, pthread_mutex_t *mutex_fork);
static int	on_first_list(t_ll_p *__, pthread_mutex_t *mutex_fork);
static int	own_fork_end(t_ll_p *__);

int	take_first_fork(t_ll_p	*__)
{
	if (__->id % 2 == 0)
	{
		__->err = pthread_mutex_lock(&__->mutex_fork);
		if (__->err)
			return ((long int) return_error(1, __->err, 1));
		if (print_philo(__, FORK1))
			return (1);
		__->fork = 1;
		if (take_fork(__))
		{
			__->err = pthread_mutex_unlock(&__->mutex_fork);
			if (__->err)
				return_error(2, __->err, 0);
			return (1);
		}
		__->err = pthread_mutex_unlock(&__->mutex_fork);
		if (__->err)
			return ((long int) return_error(2, __->err, 1));
	}
	else
	{
		if (__->next)
		{
			if (on_next_list(__, &__->next->mutex_fork))
				return (1);
		}
		else
		{
			if (on_first_list(__,
					&__->list_main->linked_list_philo->mutex_fork))
				return (1);
		}
	}
	return (0);
}

static int	on_next_list(t_ll_p *__, pthread_mutex_t *mutex_fork)
{
	__->err = pthread_mutex_lock(mutex_fork);
	if (__->err)
		return ((long int) return_error(1, __->err, 1));
	__->next->fork = 1;
	if (print_philo(__, FORK1))
		return (1);
	if (own_fork_end(__))
	{
		__->err = pthread_mutex_unlock(mutex_fork);
		if (__->err)
			return_error(2, __->err, 0);
		return (1);
	}
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
	if (print_philo(__, FORK1))
		return (1);
	if (own_fork_end(__))
	{
		__->err = pthread_mutex_unlock(mutex_fork);
		if (__->err)
			return_error(2, __->err, 0);
		return (1);
	}
	__->err = pthread_mutex_unlock(mutex_fork);
	if (__->err)
		return ((long int) return_error(2, __->err, 1));
	return (0);
}

static int	own_fork_end(t_ll_p *__)
{
	__->err = pthread_mutex_lock(&__->mutex_fork);
	if (__->err)
		return ((long int) return_error(1, __->err, 1));
	if (print_philo(__, FORK2))
		return (1);
	__->fork = 1;
	my_usleep(__->list_main, __->list_main->time_to_eat);

	__->err = pthread_mutex_lock(&__->mutex_eat);
	if (__->err)
		return ((long int) return_error(1, __->err, 1));
	if (get_time(__->list_main, (unsigned long long int *) &__->eat))
		return (1);
	*__->total_eat += 1;
	__->err = pthread_mutex_unlock(&__->mutex_eat);
	if (__->err)
		return ((long int) return_error(2, __->err, 1));

	__->err = pthread_mutex_unlock(&__->mutex_fork);
	if (__->err)
		return ((long int) return_error(2, __->err, 1));
	return (0);
}
