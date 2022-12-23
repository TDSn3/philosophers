/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_p_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/23 19:53:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	init_mutex(t_ll_p *list);

t_ll_p	*ll_p_new(int id_philo, t_l_p *list_main)
{
	t_ll_p	*list;

	list = calloc(1, sizeof(t_ll_p));
	if (!list)
		return (NULL);
	list->id = id_philo;
	list->alive = 1;
	list->the_philosopher = 0;
	list->mutex_fork = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	list->mutex_eat = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	if (init_mutex(list))
		return (NULL);
	list->time = 0;
	list->err = 0;
	list->list_main = list_main;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

static int	init_mutex(t_ll_p *list)
{
	int	err;

	err = pthread_mutex_lock(&list->mutex_fork);
	if (err)
		return ((long int) return_error(1, err, 1));
	list->fork = 0;
	err = pthread_mutex_unlock(&list->mutex_fork);
	if (err)
		return ((long int) return_error(2, err, 1));
	err = pthread_mutex_lock(&list->mutex_eat);
	if (err)
		return ((long int) return_error(1, err, 1));
	list->eat = 0;
	list->total_eat = ft_calloc(1, sizeof(int));
	if (!list->total_eat)
		return (1);
	err = pthread_mutex_unlock(&list->mutex_eat);
	if (err)
		return ((long int) return_error(2, err, 1));
	return (0);
}
