/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:38:05 by havyilma          #+#    #+#             */
/*   Updated: 2023/06/01 21:43:08 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_rfork(t_table *table, t_philo *philo)
{
	if (!ft_dead(table, philo))
		return (0);
	if (ft_check_destroy(table) == 0)
		return (0);
	if (ft_repeat(table))
	{
		pthread_mutex_lock (philo->right_fork);
		printf("+++++\n");
		ft_print (table, philo, 1);
		return (1);
	}
	return (0);
}

int	ft_lfork(t_table *table, t_philo *philo)
{
	if (!ft_dead(table, philo))
		return (0);
	if (ft_check_destroy(table) == 0)
		return (0);
		printf("-------\n");
	if (ft_repeat(table))
	{
		pthread_mutex_lock (philo->left_fork);
		ft_print (table, philo, 1);
		return (1);
	}
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	ft_eating (t_table *table, t_philo *philo)
{
	if (!ft_dead(table, philo))
		return (0);
	if (ft_check_destroy(table) == 0)
		return (0);
	if (ft_repeat(table))
	{
		pthread_mutex_lock(&(table->last_meal));
		*(philo->eaten) += 1;
		philo->last_eat = ft_get_time();
		ft_print (table, philo, 2);
		pthread_mutex_unlock(&(table->last_meal));
		if(!ft_wait(table->time_to_eat + ft_get_time(), table, philo))
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			return(0);
		}
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		if (table->argc == 6)
		{
			pthread_mutex_lock(&(table->last_meal));
			if(*philo->eaten == table->time_to_re)
			{
				pthread_mutex_unlock(philo->right_fork);
				pthread_mutex_unlock(philo->left_fork);
				pthread_mutex_unlock(&(table->last_meal));
				return (0);
			}
		}
		pthread_mutex_unlock(&(table->last_meal));
		return (1);
	}

	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&table->count);
	return (0);
}

int	ft_sleeping(t_table *table, t_philo *philo)
{
	if (!ft_dead(table, philo))
		return (0);
	if (ft_check_destroy(table) == 0)
		return (0);
	if (ft_repeat(table))
	{
		ft_print(table, philo, 3);
		return (1);
	}
	return (0);
}

int	ft_thinking(t_table *table, t_philo *philo)
{
	if (!ft_dead(table, philo))
		return (0);
	if (ft_check_destroy(table) == 0)
		return (0);
	if (ft_repeat(table))
	{
		ft_print(table, philo, 4);
		return (1);
	}
	return (0);
}
