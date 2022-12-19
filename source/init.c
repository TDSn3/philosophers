/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:21:12 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/19 00:02:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	ft_atoi(const char *nptr);
static int	init_ll_p(t_l_p *list_main);
static int	mutex_init_var_start(t_l_p *list_main);

int	init(t_l_p *list_main, int argc, char **argv)
{
	list_main->number_of_philosophers = ft_atoi(argv[1]);
	if (list_main->number_of_philosophers > PTHREAD_KEYS_MAX)
		return (1);
	list_main->time_to_die = ft_atoi(argv[2]);
	list_main->time_to_eat = ft_atoi(argv[3]);
	list_main->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		list_main->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	if (init_ll_p(list_main))
		return (1);
	list_main->mutex_start = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_init(&list_main->mutex_start, NULL);
	if (mutex_init_var_start(list_main))
		return (1);
	return (0);
}

static int	mutex_init_var_start(t_l_p *list_main)
{
	int	err;

	err = pthread_mutex_lock(&list_main->mutex_start);
	if (err)
	{
		ft_putstr_fd("Error : pthread_mutex_lock\n", 2);
		return (1);
	}
	list_main->start = 0;
	err = pthread_mutex_unlock(&list_main->mutex_start);
	if (err)
	{
		ft_putstr_fd("Error : pthread_mutex_unlock\n", 2);
		return (1);
	}
	return (0);
}

static int	init_ll_p(t_l_p *list_main)
{
	int		i;
	t_ll_p	*new_list;

	i = 0;
	list_main->linked_list_philo = NULL;
	while (i < list_main->number_of_philosophers)
	{
		new_list = ll_p_new(i + 1, list_main);
		if (!new_list)
		{
			ll_p_clear(&list_main->linked_list_philo);
			ft_putstr_fd("Error : malloc\n", 2);
			return (1);
		}
		ll_p_add_back(&list_main->linked_list_philo, new_list);
		i++;
	}
	return (0);
}

static int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	nb;
	long long int	final_nb;
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
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	return (final_nb = nb * if_is_negative);
}
