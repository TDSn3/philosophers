/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:25:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/22 13:55:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	my_usleep(t_l_p *list_main, unsigned long long int time_stop)
{
	unsigned long long int	time;
	unsigned long long int	start_time;

	if (get_time(list_main, &time) || get_time(list_main, &start_time))
		return (1);
	while (time - start_time < time_stop)
	{
		usleep(500);
		if (get_time(list_main, &time))
			return (1);
	}
	return (0);
}
