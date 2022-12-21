/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:17:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/21 22:30:46 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	get_time(t_l_p *list_main, unsigned long long int *time)
{
	struct timeval			tv;

	if (gettimeofday(&tv, NULL))
		return ((long int) return_error(3, errno, 1));
	*time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000))
		- list_main->timestamp;
	return (0);
}
