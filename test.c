#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

typedef struct fork
{
	pthread_mutex_t	*used;
}	t_fork;

typedef struct philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int	id;
	int	dead;
	pthread_t		philo;
}	t_philo;

void	start_routine(t_philo *philo)
{
	printf("test");
}

int main(int argc, char **argv)
{
	int nb = atoi(argv[1]);
	t_philo *philos=malloc(nb); 
	pthread_mutex_t *fork = malloc(nb);
	if (!fork)
		return (1);

	pthread_create(&(philos[0].philo), NULL, (void *)start_routine, &philos[0]);
}
