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

void	cleanup_forks(pthread_mutex_t *forks, int num_of_philo)
{
	size_t	i;

	if (!forks)
		return ;
	i = 0;
	while (i < num_of_philo)
		pthread_mutex_destroy(&forks[i++]);
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
