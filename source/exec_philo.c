/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:31:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/21 23:23:08 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	philo_sleep(t_ll_p	*__);
static void	*alive_zero(t_ll_p *__);

void	*exec_philo(void *data)
{
	t_ll_p	*__;

	__ = (t_ll_p *) data;
	if (__->id % 2 == 0)
		usleep(__->list_main->time_to_eat * 1000);
	while (1)
		if (take_first_fork(__) || philo_sleep(__))
			return (alive_zero(__));
	return (alive_zero(__));
}

static void	*alive_zero(t_ll_p *__)
{
	__->alive = 0;
	return (NULL);
}

static int	philo_sleep(t_ll_p	*__)
{
	if (print_philo(__, SLEEPING))
		return (1);
	usleep(__->list_main->time_to_sleep * 1000);
	if (print_philo(__, THINKING))
		return (1);
	return (0);
}
