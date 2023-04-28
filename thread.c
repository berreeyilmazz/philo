#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int j = 0;
pthread_mutex_t	mutex;

void	*routine(void *vargp)
{
	int k = 0;
	while (k++ < 1000000)
	{
		pthread_mutex_lock(&mutex);
		j++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main()
{
	int	i = 0;
	char *string = "melih";
	pthread_t	id;
	pthread_mutex_init(&mutex, NULL);
	while (i++ < 3)
	{
		pthread_create(&id, NULL, &routine, string);
	}
	i = 0;
	while (i++ < 3)
	{
		pthread_join(id, NULL);
	}
	printf("j: %d\n", j);
	return (0);
}