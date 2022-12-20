/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:29:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/19 22:18:25 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define _GNU_SOURCE

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <errno.h>

# include "struct.h"

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		check_error(int argc, char **argv);
int		init(t_l_p *list_main, int argc, char **argv);
void	*exec_philo(void *data);
int		start_all_thread(t_l_p *list_main);
void	wait_thread(t_l_p *list_main);
int		take_fork(t_l_p *list_main, t_ll_p *own_ll_p, int *eat, t_l_ep	*__);
int		check_die(t_l_p *list_main, t_ll_p *own_ll_p, int eat, t_l_ep *__);
int		check_die2(t_l_p *list_main, t_ll_p *own_ll_p, int eat, t_l_ep *__);
int		free_all(int return_value, t_l_p *list_main);
void	*return_error(int var_err, int err, long int nb_return);

#endif
