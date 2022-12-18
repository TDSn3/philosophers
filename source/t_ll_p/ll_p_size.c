/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_p_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:59:36 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/18 04:25:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	ll_p_size(t_ll_p *list)
{
	size_t	i;
	t_ll_p	*next_list;

	if (!list)
		return (0);
	i = 0;
	next_list = list;
	while (next_list)
	{
		i++;
		next_list = next_list->next;
	}
	return (i);
}
