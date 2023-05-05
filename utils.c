/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:11:35 by havyilma          #+#    #+#             */
/*   Updated: 2023/05/05 16:36:34 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *ac)
{
	int i = 0;
	while (ac[i])
		i++;
	return (i);
}

int	ft_atoi(char *ac)
{
	int	i;
	int	rtrn;
	int	sign;

	rtrn = 0;
	i = 0;
	sign = 1;
	while (i < ft_strlen(ac) && (ac[i] >= 48 && ac[i] <= 57))
	{
		rtrn = rtrn * 10 + (ac[i] - 48);
		i++;
	}
	return (rtrn);
}

int	ft_check_av(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (!(ac == 5 || ac == 6))
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	while (av[++i])
	{
		while (av[i][++j])
		{
			if (!(av[i][j] >= 48 && av[i][j] <= 57))
			{
				printf("Invalid type of argument\n");
				return (0);
			}
		}
		j = -1;
	}
	return (1);
}

int	ft_check_if_neg (t_table *table)
{
	if (table->nmb_of_phork <= 0
		|| table->time_to_die <= 0
		|| table->time_to_eat <= 0
		|| table->time_to_sleep <= 0
		|| table->time_to_re <= 0)
		return (0);
	return (1);
}

int	lets_take_av(t_table *table, char **av, int ac)
{
	/* UNUTMA while (av[++i])
		while (av[i][++j])
			if (!(av[i][j] >= 48 && av[i][j] <= 57))
				return (0);*/
	table->nmb_of_phork = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->time_to_re = ft_atoi(av[5]);
	else
		table->time_to_re = -2;
	table->philos = malloc(sizeof(t_philo) * table->nmb_of_phork);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nmb_of_phork);
	ft_create_philos(table);
	return (1);
}