/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:00:28 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/16 23:16:19 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	str_isdigit(char *str);

int	check_error(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (1);
	i = 1;
	while (argv[i])
	{
		if (str_isdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
		if (str[i] < '0' || str[i++] > '9')
			return (1);
	return (0);
}
