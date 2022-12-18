/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:11:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/18 15:51:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

struct	s_linked_list_philo;

/* ************************************************************************** */

typedef struct s_list_philo {
	int							number_of_philosophers;
	int							time_to_die;
	int							time_to_eat;
	int							time_to_sleep;
	int							number_of_times_each_philosopher_must_eat;
	pthread_mutex_t				mutex;
	struct s_linked_list_philo	*linked_list_philo;
	int							timestamp;
	int							start;
}	t_l_p;

/* ************************************************************************** */

typedef struct s_linked_list_philo
{
	int							id;
	int							alive;
	pthread_t					the_philosopher;
	int							fork;
	struct s_list_philo			*list_main;
	struct s_linked_list_philo	*prev;
	struct s_linked_list_philo	*next;
}	t_ll_p;

int								ll_p_add_back(t_ll_p **list, t_ll_p *new);
void							ll_p_clear(t_ll_p **lst);
t_ll_p							*ll_p_last(t_ll_p *list);
t_ll_p							*ll_p_new(int id_philo, t_l_p *list_main);
int								ll_p_size(t_ll_p *list);

/* ************************************************************************** */

#endif
