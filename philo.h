/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:51:44 by havyilma          #+#    #+#             */
/*   Updated: 2023/05/05 17:31:16 by havyilma         ###   ########.fr       */
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
	pthread_mutex_t *dead;
	t_philo			*philos;
	long long		start_time;
	int				is_she_dead;

}			t_table;


int 	lets_take_av (t_table *table, char **av, int ac);
void	*ft_routine(void *vargs);
int 	ft_strlen(char *ac);
int		ft_atoi(char *ac);
int		ft_create_philos(t_table *table);
int		ft_check_av(int ac, char **av);
int		ft_check_if_neg (t_table *table);
int		ft_create_philos(t_table *table);
int		ft_create_thread(t_table *table);
long long	ft_get_time();
void	ft_wait(long long milisec, t_table *table);











#endif