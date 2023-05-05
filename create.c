/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:35:42 by havyilma          #+#    #+#             */
/*   Updated: 2023/05/05 17:39:15 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nmb_of_phork)
	{
		table->philos[i].id_num = i + 1;
		table->philos[i].table = table;
		table->philos[i].right_fork = &table->forks[i];
		table->philos[i].left_fork = &table->forks[(i + 1) % table->nmb_of_phork];
		table->is_she_dead = 0;
		pthread_mutex_init(&table->forks[i], NULL);
	}
	return (0);
}

int	ft_create_thread(t_table *table)
{
	int i;

	i = -1;
	table->start_time = ft_get_time();
	while (++i < table->nmb_of_phork)
	{
		pthread_create(&(table->philos[i].thread_id), NULL, &ft_routine, (void *)&table->philos[i]);
		usleep(100);
	}
	i = -1;

	while (++i < table->nmb_of_phork)
		pthread_join(table->philos[i].thread_id, NULL);

	return (1);
}