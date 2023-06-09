/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:49:18 by havyilma          #+#    #+#             */
/*   Updated: 2023/05/21 01:33:27 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main (int ac, char **av)
{
	t_table	table;

	if (!(ft_check_av(ac, av)))
		return (0);
	table.argc = ac;
	if (!(ft_take_av(&table, av, ac)))
		return (0);
	if (!(ft_create_thread(&table)))
		return (0);
	
	return (0);

}