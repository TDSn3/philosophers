/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_p_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/21 21:50:10 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	init_fork(t_ll_p *list);

t_ll_p	*ll_p_new(int id_philo, t_l_p *list_main)
{
	t_ll_p	*list;

	list = malloc(sizeof(t_ll_p));
	if (!list)
		return (NULL);
	list->id = id_philo;
	list->alive = 1;
	list->the_philosopher = 0;
	list->mutex_fork = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	if (init_fork(list))
		return (NULL);
	list->time = 0;
	list->err = 0;
	list->list_main = list_main;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

static int	init_fork(t_ll_p *list)
{
	int	err;

	err = pthread_mutex_lock(&list->mutex_fork);
	if (err)
	{
		ft_putstr_fd("Error: ll_p_new: init_fork: ", 2);
		if (err == EINVAL)
			ft_putstr_fd("mutex not initialized\n", 2);
		if (err == EDEADLK)
			ft_putstr_fd("already locked by a different thread\n", 2);
		return (1);
	}
	list->fork = 0;
	list->eat = 0;
	err = pthread_mutex_unlock(&list->mutex_fork);
	if (err)
	{
		ft_putstr_fd("Error: ll_p_new: init_fork: ", 2);
		if (err == EINVAL)
			ft_putstr_fd("mutex not initialized\n", 2);
		if (err == EPERM)
			ft_putstr_fd("the thread has no control over the mutex\n", 2);
		return (1);
	}
	return (0);
}
