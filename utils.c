/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:11:35 by havyilma          #+#    #+#             */
/*   Updated: 2023/04/30 17:31:03 by havyilma         ###   ########.fr       */
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
/*
void	*ft_rou(void *my_turn)
{
//	pthread_mutex_t	mutex;
	int i = 0;
	int *number = (int *)my_turn;
	while (i <= ft_atoi(my_turn))
	{
		pthread_mutex_lock(&mutex);
		printf ("philo %d\n", i);
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return (NULL);
}
*/