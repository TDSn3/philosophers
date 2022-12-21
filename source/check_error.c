/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:00:28 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/21 12:55:09 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	int_max_min(const char *nptr);
static int	int_max_min_next(
				const char *nptr,
				unsigned int *i,
				unsigned int *nb,
				int if_is_negative);

int	check_error(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (1);
	i = 1;
	while (argv[i])
	{
		if (int_max_min(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	int_max_min(const char *nptr)
{
	unsigned int	i;
	unsigned int	nb;
	int				if_is_negative;

	i = 0;
	nb = 0;
	if_is_negative = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			if_is_negative = -1;
		i++;
	}
	if (int_max_min_next(nptr, &i, &nb, if_is_negative))
		return (1);
	return (0);
}

static int	int_max_min_next(
	const char *nptr,
	unsigned int *i,
	unsigned int *nb,
	int if_is_negative)
{
	while (nptr[*i])
	{
		if (nptr[*i] < '0' || nptr[*i] > '9')
			return (1);
		*nb = (*nb * 10) + (nptr[*i] - 48);
		if ((if_is_negative == 1 && *nb > 2147483647)
			|| (if_is_negative == -1))
			return (1);
		*i += 1;
	}
	return (0);
}
