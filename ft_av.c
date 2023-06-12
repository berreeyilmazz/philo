/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_av.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:40:57 by havyilma          #+#    #+#             */
/*   Updated: 2023/06/12 15:22:43 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_strlen(char *ac)
{
	int	i;

	i = 0;
	while (ac[i])
		i++;
	return (i);
}

int	ft_atoi(char *ac)
{
	int	i;
	int	rtrn;

	rtrn = 0;
	i = -1;
	while (++i < ft_strlen(ac))
		rtrn = rtrn * 10 + (ac[i] - 48);
	return (rtrn);
}

int	ft_take_av(t_table *table, char **av, int ac)
{
	table->argc = ac;
	table->nmb_of_phork = ft_atoi(av[1]);
	if (table->nmb_of_phork == 1)
		return (0);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->time_to_re = ft_atoi(av[5]);
	else if (ac == 5)
		table->time_to_re = -1;
	return (1);
}
