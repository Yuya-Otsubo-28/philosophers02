#include "../include/struct.h"
#include <stdlib.h>

void	cleanup_philos(t_philo **philos, int num_of_philo)
{
	size_t	i;

	if (!philos)
		return ;
	i = 0;
	while (philos[i] && i < num_of_philo)
		free(philos[i++]);
	free(philos);
}

void	cleanup_fork(t_fork *fork)
{
	if (!fork)
		return ;
	pthread_mutex_destroy(&(fork->mtx));
	free(fork);
}

void	cleanup_forks(t_fork **forks, int num_of_philo)
{
	size_t	i;

	if (!forks)
		return ;
	i = 0;
	while (forks[i] && i < num_of_philo)
		cleanup_fork(forks[i++]);
	free(forks);
}

void	cleanup_data(t_data *data)
{
	if (!data)
		return ;
	cleanup_philos(data->philos, data->num_of_philo);
	cleanup_forks(data->forks, data->num_of_philo);
	free(data);
}
