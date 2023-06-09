/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:33:07 by havyilma          #+#    #+#             */
/*   Updated: 2023/06/01 21:40:11 by havyilma         ###   ########.fr       */
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
	while (ft_get_time() < milisec)
	{
		if (!ft_dead(table, philo))
			return (0);
		if (!ft_imdead(table, philo))
			return (0);
		usleep(50);
	}
	return (1);
}