/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:55:15 by havyilma          #+#    #+#             */
/*   Updated: 2023/06/12 19:42:31 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void ft_destroy(t_table *table)
{
    int i;

    i = 0;
    while (i < table->nmb_of_phork)
    {
        pthread_mutex_destroy(&(table->forks[i]));
        i++;
    }
    pthread_mutex_destroy(&(table->is_she_dead));
    pthread_mutex_destroy(&(table->last_meal));
    pthread_mutex_destroy(&(table->print));
    pthread_mutex_destroy(&(table->count));
    pthread_mutex_destroy(&(table->ctrl));
    pthread_mutex_lock(&(table->destroy));
    table->dest = 10;
    pthread_mutex_unlock(&(table->destroy));
}

int ft_check_destroy(t_table *table)
{
    pthread_mutex_lock(&(table->destroy));
    if(table->dest == 10)
    {
        pthread_mutex_unlock(&(table->destroy));
        return(0);
    }
    pthread_mutex_unlock(&(table->destroy));
    return(1);
}*/