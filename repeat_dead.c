/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_dead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:37:38 by havyilma          #+#    #+#             */
/*   Updated: 2023/06/12 21:15:37 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_imdead(t_table *table)
{
	int	i;

	i = 0;
	while(i < table->nmb_of_phork)
	{
		if (ft_get_time() - table->philos[i].last_eat >= table->time_to_die)
		{
			*table->dead += 1;
			if (*table->dead == 1)
				ft_print (table, &table->philos[i], 5);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_dead(t_table *table)
{
	if (*table->dead == 1)
	{
		return (0);
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
	while (i < table->nmb_of_phork)
	{
		if (*table->philos[i].eaten != table->time_to_re)
		{
			pthread_mutex_unlock(&table->count);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&table->count);
	return (0);
}

int	ft_check(t_table *table)
{
	while(1)
	{
		pthread_mutex_lock(&(table->last_meal));
		pthread_mutex_lock(&(table->is_she_dead));
		if (!ft_imdead(table))
		{
			pthread_mutex_unlock(&(table->last_meal));
			pthread_mutex_unlock(&(table->is_she_dead));
			return(0);
		}
		if (!ft_dead(table))
		{
			pthread_mutex_unlock(&(table->last_meal));
			pthread_mutex_unlock(&(table->is_she_dead));
			return (0);
		}
		pthread_mutex_unlock(&(table->last_meal));
		pthread_mutex_unlock(&(table->is_she_dead));
		usleep(500);
	}
	return (1);
}