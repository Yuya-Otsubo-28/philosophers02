#include "../include/struct.h"
#include <pthread.h>

t_data	*init_philo_num(t_data *data, char **argv)
{
	if (is_invalid_input(argv[2]))
		return (init_error(data));
	data->num_of_philo = ft_atoi(argv[2]);
	return (data);
}

t_data *init_philos(t_data *data)
{
	size_t	i;

	data->philos = (t_philo **)malloc(sizeof(t_philo *) * data->num_of_philo);
	if (!(data->philos))
		return (init_error(data));
	memset(data->philos, 0, sizeof(t_philo *) * data->num_of_philo);
	i = 0;
	while (i < data->num_of_philo)
	{
		data->philos[i] = init_philo();
		if (!(data->philos[i]))
			return (init_error(data));
		i++;
	}
	return (data);
}

t_fork	*init_fork(int i)
{
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	if (pthread_mutex_init(&(fork->mtx), NULL))
		return (NULL);
	fork->id = i;
	return (fork);
}

t_data	*init_forks(t_data *data)
{
	size_t	i;
	int		res;

	data->forks = (t_fork **)malloc(sizeof(t_fork *) * data->num_of_philo);
	if (!(data->forks))
		return (init_error(data));
	memset(data->forks, 0, sizeof(t_fork *) * data->num_of_philo);
	i = 0;
	while (i < data->num_of_philo)
	{
		data->forks[i] = init_fork(i);
		if (!(data->forks[i]))
			return (init_error(data));
		i++;
	}
	return (data);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (data);
	memset(data, 0, sizeof(t_data));
	data = init_philo_num(data, argv);
	if (!data)
		return (NULL);
	data = init_forks(data);
	if (!data)
		return (NULL);
	data = init_philos(data);
	if (!data)
		return (NULL);
	data = init_time(data, argv);
	if (!data)
		return (NULL);
	data = init_must_eat(data, argc, argv);
	if (!data)
		return (NULL);
	return (data);
}
