#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t	mutex;

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

void	*ft_routine (void *my_turn)
{
//	pthread_mutex_t	mutex;
	int i = 0;
	int *number = (int *)my_turn;
	printf("dsafdsfsd %d\n", *number);
	while (i < ft_atoi(my_turn))
	{
		pthread_mutex_lock(&mutex);
		printf ("philo %d\n", i);
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	int	i;
	int	*number;
	(void)av;
//	pthread_mutex_t	mutex;
	pthread_t		id;

	i = 1;
	number = malloc(sizeof(int));
	*number = 4;
	pthread_mutex_init(&mutex, NULL);
	while (i < ac - 1)
	{
		pthread_create (&id, NULL, &ft_routine, (void *)number);
		i++;
	}
	i = 0;
	while (i++ < ac - 1)
		pthread_join(id, NULL);
	return (0);
}