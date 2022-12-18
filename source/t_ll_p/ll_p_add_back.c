/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_p_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:18:44 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/18 05:46:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	ll_p_add_back(t_ll_p **list, t_ll_p *new)
{
	t_ll_p	*copy;

	if (!new)
		return (1);
	if (list)
	{
		if (!*list)
			*list = new;
		else
		{
			copy = ll_p_last(*list);
			copy->next = new;
			copy->next->prev = copy;
		}
	}
	return (0);
}
