/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_dead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:37:38 by havyilma          #+#    #+#             */
/*   Updated: 2023/06/01 21:40:40 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_imdead(t_table *table, t_philo *philo)
{
	pthread_mutex_lock(&(table->last_meal));
	if (ft_get_time() - philo->last_eat >= table->time_to_die)
	{
		pthread_mutex_lock(&(table->is_she_dead));
		*table->dead = 1;
		pthread_mutex_unlock(&(table->is_she_dead));
		pthread_mutex_unlock(&(table->last_meal));
		return (0);
	}
	pthread_mutex_unlock(&(table->last_meal));
	return (1);
}

int	ft_dead(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(table->last_meal));
	if (ft_get_time() - philo->last_eat >= table->time_to_die)
	{
		pthread_mutex_lock(&(table->is_she_dead));
		*table->dead += 1;
		pthread_mutex_unlock(&(table->is_she_dead));
		pthread_mutex_unlock(&(table->last_meal));
		return (0);
	}
	pthread_mutex_unlock(&(table->last_meal));
	while (i < table->nmb_of_phork)
	{
		pthread_mutex_lock(&(table->is_she_dead));
		if (*table->dead == 1)
		{
			pthread_mutex_lock(&(table->ctrl));
			if (*table->control == 0)
			{
				ft_print (table, philo, 5);
				*table->control = 1;
			}
			pthread_mutex_unlock(&(table->is_she_dead));
			pthread_mutex_unlock(&table->ctrl);
			ft_destroy(table);
			return (0);
		}
		i++;
		pthread_mutex_unlock(&(table->is_she_dead));
	}
	return (1);
}

int	ft_repeat(t_table *table)
{
	int	i;

	i = 0;
	if(table->argc == 5)
		return(1);
	pthread_mutex_lock(&table->count);
	pthread_mutex_lock(&(table->last_meal));
	while (i < table->nmb_of_phork)
	{
		if (*table->philos[i].eaten != table->time_to_re)
		{
			pthread_mutex_unlock(&table->count);
			pthread_mutex_unlock(&(table->last_meal));
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&table->count);
	pthread_mutex_unlock(&(table->last_meal));
	return (0);
}