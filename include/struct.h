/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:11:18 by tda-silv          #+#    #+#             */
/*   Updated: 2022/12/17 02:30:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/* ************************************************************************** */

typedef struct s_list_int
{
	int					id;
	pthread_t			the_philosopher;
	pthread_mutex_t		fork;
	struct s_list_int	*prev;
	struct s_list_int	*next;
}	t_li;

int						li_add_back(t_li **lst, t_li *new);
void					li_clear_one(t_li **lst, int content);
void					li_clear(t_li **lst);
t_li					*li_last(t_li *lst);
t_li					*li_new(int content_one, int content_two);
int						li_size(t_li *lst);
int						li_find_content(t_li *lst, int pid);

/* ************************************************************************** */

typedef struct s_philo {
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	pthread_t			the_philosophers[PTHREAD_KEYS_MAX];
	t_li				*list_philo;
}	t_philo;

/* ************************************************************************** */

#endif
