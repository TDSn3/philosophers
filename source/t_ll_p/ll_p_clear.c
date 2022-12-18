/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_p_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:19:08 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/18 05:04:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ll_p_clear(t_ll_p **list)
{
	t_ll_p	**copy;
	t_ll_p	*copy_two;

	copy = list;
	if (!*list)
		return ;
	while (*copy)
	{
		copy_two = (*copy)->next;
		(*copy)->id = 0;
		free((*copy)->the_philosopher);
		(*copy)->list_main = NULL;
		free(*copy);
		*copy = copy_two;
	}
	*list = NULL;
}
