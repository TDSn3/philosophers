/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:16:38 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/21 23:51:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	print_error_pthread_mutex_lock(int err);
static void	print_error_pthread_mutex_unlock(int err);
static void	print_error_gettimeofday(int err);

/* ************************************************************************** */
/*                                                                            */
/*   var_err == 1 | pthread_mutex_lock										  */
/*   var_err == 2 | pthread_mutex_unlock									  */
/*   var_err == 3 | gettimeofday											  */
/*                                                                            */
/* ************************************************************************** */

void	*return_error(int var_err, int err, long int nb_return)
{
	if (nb_return)
	{
		if (var_err == 1)
			print_error_pthread_mutex_lock(err);
		if (var_err == 2)
			print_error_pthread_mutex_unlock(err);
		if (var_err == 3)
			print_error_gettimeofday(err);
		return ((void *) nb_return);
	}
	else
	{
		if (var_err == 1)
			print_error_pthread_mutex_lock(err);
		if (var_err == 2)
			print_error_pthread_mutex_unlock(err);
		if (var_err == 3)
			print_error_gettimeofday(err);
		return (NULL);
	}
	return (NULL);
}

static void	print_error_pthread_mutex_lock(int err)
{
	ft_putstr_fd("Error: pthread_mutex_lock: ", 2);
	if (err == EINVAL)
		ft_putstr_fd("mutex not initialized\n", 2);
	if (err == EDEADLK)
		ft_putstr_fd("already locked by a different thread\n", 2);
}

static void	print_error_pthread_mutex_unlock(int err)
{
	ft_putstr_fd("Error: pthread_mutex_unlock: ", 2);
	if (err == EINVAL)
		ft_putstr_fd("mutex not initialized\n", 2);
	if (err == EPERM)
		ft_putstr_fd("the thread has no control over the mutex\n", 2);
}

static void	print_error_gettimeofday(int err)
{
	ft_putstr_fd("Error: gettimeofday: ", 2);
	if (err == EFAULT)
		ft_putstr_fd("invalid pointer\n", 2);
	if (err == EINVAL)
		ft_putstr_fd("invalid time zone\n", 2);
	if (err == EPERM)
		ft_putstr_fd("not privileges to call settimeofday\n", 2);
}
