/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 06:24:08 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/18 06:46:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	free_all(int return_value, t_l_p *list_main)
{
	ll_p_clear(&list_main->linked_list_philo);
	return (return_value);
}
