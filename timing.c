/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:33:07 by havyilma          #+#    #+#             */
/*   Updated: 2023/06/12 21:16:04 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	ft_get_time()
{
	struct timeval mikro;

	gettimeofday(&mikro, NULL);
	return((mikro.tv_sec * 1000) + mikro.tv_usec / 1000);
}

int	ft_wait(long long milisec, t_table *table, t_philo *philo)
{
	int i;
	(void )philo;

	i = 0;
	while ((ft_get_time() < milisec))
	{
		pthread_mutex_lock(&(table->last_meal));
		pthread_mutex_lock(&(table->is_she_dead));
		if (!ft_imdead(table))
			return (0);
		if (!ft_dead(table))
			return (0);
		pthread_mutex_unlock(&(table->last_meal));
		pthread_mutex_unlock(&(table->is_she_dead));
		i++;
		if (i == table->nmb_of_phork)
			i = 0;
		usleep(50);
	}
	return (1);
}