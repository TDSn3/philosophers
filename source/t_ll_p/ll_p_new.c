/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_p_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/18 06:20:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_ll_p	*ll_p_new(int id_philo, t_l_p *list_main)
{
	t_ll_p	*list;

	list = malloc(sizeof(t_ll_p));
	if (!list)
		return (NULL);
	list->id = id_philo;
	list->the_philosopher = 0;
	list->fork = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	list->list_main = list_main;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}
