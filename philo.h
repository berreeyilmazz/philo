/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:51:44 by havyilma          #+#    #+#             */
/*   Updated: 2023/04/30 20:18:20 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table	*table;
	int				id_num;
	pthread_t		thread_id;

}			t_philo;

typedef struct s_table
{
	struct s_rules	*rules;
	int				nmb_of_phork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_re;
	pthread_mutex_t	*forks;
	t_philo			*philos;

}			t_table;


int lets_take_av (t_table *table, char **av, int i, int j);
void	*ft_routine(void *vargs);
int ft_strlen(char *ac);
int	ft_atoi(char *ac);
int	ft_create_philo(t_table *table);







#endif