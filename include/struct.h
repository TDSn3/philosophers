/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:11:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/23 01:46:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

struct	s_list_philo;
struct	s_linked_list_philo;
struct	s_list_exec_philo;

/* ************************************************************************** */

typedef struct s_list_philo {
	int							argc;
	int							number_of_philosophers;
	int							time_to_die;
	int							time_to_eat;
	int							time_to_sleep;
	int							number_of_times_each_philosopher_must_eat;
	int							end_eat;
	struct s_linked_list_philo	*linked_list_philo;
	unsigned long long int		timestamp;
	pthread_mutex_t				mutex_start;
	int							all_alives;
}	t_l_p;

/* ************************************************************************** */

typedef struct s_linked_list_philo
{
	int							id;
	int							alive;
	pthread_t					the_philosopher;
	pthread_mutex_t				mutex_fork;
	int							fork;
	struct timeval				tv;
	unsigned long long int		time;
	pthread_mutex_t				mutex_eat;
	int							eat;
	int							total_eat;
	int							err;
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

typedef enum e_prompt {
	FORK1,
	FORK2,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_print;

#endif
