/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:35:59 by havyilma          #+#    #+#             */
/*   Updated: 2023/05/05 18:21:04 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *vargs)
{
	t_philo	*philo;
	t_table	*table;
	int	a;

	a = 0;
	philo = (t_philo *)vargs;
	table = philo->table;
	while (table->is_she_dead != 1 || table->time_to_re > a)    /// while (1)
	{
		if (table->is_she_dead != 0)
		{
			printf("dead\n");
			return(NULL);

		}
		pthread_mutex_lock(philo->right_fork);
		printf("%lld %d has taken a fork\n", (ft_get_time() - table->start_time), philo->id_num);
		pthread_mutex_lock(philo->left_fork);
		printf("%lld %d has taken a fork\n", (ft_get_time() - table->start_time), philo->id_num);
		printf("%lld %d is eating\n", (ft_get_time() - table->start_time), philo->id_num);
		ft_wait((ft_get_time() + table->time_to_eat), table);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		a++;
		printf("%lld %d is sleeping\n", (ft_get_time() - table->start_time), philo->id_num);
		ft_wait((ft_get_time() + table->time_to_sleep), table);
		printf("%lld %d is thinking\n", (ft_get_time() - table->start_time), philo->id_num);
		if (table->time_to_die == (ft_get_time() - table->start_time))
		{
			printf("%lld %d is dead\n", (ft_get_time() - table->start_time), philo->id_num);
			table->is_she_dead++;
			printf("öldüm\n");
			return (NULL);
		}
	}
	return (NULL);
}

int	ft_deneme(t_table *table)
{
	table->forks = malloc(sizeof(pthread_mutex_t) * 1);
	return(0);
}
int	main(int ac, char **av)
{
	t_table table;

	if (!ft_check_av(ac, av))
		return (0);
	lets_take_av(&table, av, ac);
	if (!ft_check_if_neg(&table))
		return (0);

	if (!ft_create_thread(&table))
		return (0);
	return (0);
}