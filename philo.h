/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:32:09 by havyilma          #+#    #+#             */
/*   Updated: 2023/06/12 21:13:28 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread_id;
	int				id_num;
	struct s_table	*table;
	long long		last_eat;
	int				*im_dead;
	int				*eaten;

}					t_philo;

typedef struct s_table
{
	int				nmb_of_phork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_re;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	is_she_dead;
	pthread_mutex_t	last_meal;
	pthread_mutex_t	print;
	pthread_mutex_t	count;
	pthread_mutex_t	ctrl;
	pthread_mutex_t	dst;
	int				*dead;
	int				*eat;
	long long		start;
	int				argc;
	int				*control;
	int				dest;

}					t_table;

int		ft_check_av(int ac, char **av);
int		ft_strlen(char *ac);
int		ft_atoi(char *ac);
int		ft_take_av(t_table *table, char **av, int ac);
void	ft_create_philos_and_table(t_table *table);
int		ft_dead(t_table *table);
int		ft_repeat(t_table *table);
int		ft_print(t_table *table, t_philo *philo, int p);
int		ft_eating (t_table *table, t_philo *philo);
int		ft_sleeping(t_table *table, t_philo *philo);
void	*ft_routine(void *arg);
int		ft_create_thread(t_table *table);
int		ft_get_time();
int		ft_wait(long long milisec, t_table *table, t_philo *philo);
int		ft_imdead(t_table *table);
int		ft_check(t_table *table);


#endif