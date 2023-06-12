/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:38:05 by havyilma          #+#    #+#             */
/*   Updated: 2023/06/12 21:09:29 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eating (t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&table->is_she_dead);
	if (*table->dead >= 1)
	{
		pthread_mutex_unlock(&table->is_she_dead);
		return (0);
	}
	pthread_mutex_unlock(&table->is_she_dead);
	pthread_mutex_lock (philo->right_fork);
	if(!ft_print (table, philo, 1))
		return (0);
	pthread_mutex_lock (philo->left_fork);
	if(!ft_print (table, philo, 1))
		return(0);
	pthread_mutex_lock(&(table->last_meal));
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(&(table->last_meal));
	if (!ft_print (table, philo, 2))
		return (0);
	pthread_mutex_lock(&table->count);
	*(philo->eaten) += 1;
	pthread_mutex_unlock(&table->count);
	if(!ft_wait(table->time_to_eat + ft_get_time(), table, philo))
		return (0);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (1);
}

int	ft_sleeping(t_table *table, t_philo *philo)
{
	if (!ft_print(table, philo, 3))
		return (0);
	return (1);
}
