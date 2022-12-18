/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:52:12 by tda-silv          #+#    #+#             */
/*   Updated: 2022/06/19 11:17:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_ll_p	*ll_p_last(t_ll_p *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}
