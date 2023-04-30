#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "philo.h"

int lets_take_av (t_table *table, char **av, int i, int j)
{
	/* UNUTMA while (av[++i])
		while (av[i][++j])
			if (!(av[i][j] >= 48 && av[i][j] <= 57))
				return (0);*/
	table->nmb_of_phork = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		table->time_to_re = ft_atoi(av[5]);
	else
		table->time_to_re = 0;
	table->philos = malloc(sizeof(t_philo) * table->nmb_of_phork);
	ft_create_philo(table);
	return (1);
}

void	*ft_routine(void *vargs)
{
	t_philo	*philo;

	philo = (t_philo *) vargs;
	pthread_mutex_lock(left);
	printf("philo %d has taken a fork\n", philo->id_num);
	pthread_mutex_lock(right);
	printf("philo %d has taken a fork\n", philo->id_num);
	printf("philo %d is eating\n", philo->id_num);
	usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(right);
	pthread_mutex_unlock(left);
	//pthread_mutex_unlock(&data->mutex)
	// THİNKİNG SLEEPİNG HEPSİ BURADA OLACAK SİMDİLİK SİL DENEYE YANILA BULACAKSIN
	return (NULL);
}


int	ft_create_philo(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nmb_of_phork)
	{
		table->philos[i].id_num = i + 1;
		table->philos->table = table;
		printf("philo %d\n", table->philos[i].id_num);
		// FORKLARI DAĞITIYORUZ

	}
	return(1);
}

int main(int ac, char **av)
{
	t_table		table;
	int			i;

	i = -1;

	if (!lets_take_av(&table, av, 0, -1))
		return (0);

	while (++i < table.nmb_of_phork)
	{
		pthread_create (&(table.philos[i].thread_id), NULL, &ft_routine, (void *) &table.philos[i]);
		//usleep(50);
	}
	i = -1;
	while (++i < table.nmb_of_phork)
		pthread_join(table.philos[i].thread_id, NULL);
	return (0);
}