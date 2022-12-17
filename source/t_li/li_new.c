/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 02:42:35 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_li	*li_new(int id_philo, pthread_t the_philosopher)
{
	t_li	*li;

	li = malloc(sizeof(t_li));
	if (!li)
		return (NULL);
	li->content_one = content_one;
	li->content_two = content_two;
	li->next = NULL;
	li->prev = NULL;
	return (li);
}
