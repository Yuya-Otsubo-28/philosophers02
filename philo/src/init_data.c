#include "../include/struct.h"

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

t_data	*init_forks(t_data *data)
{
	size_t	i;
	int		res;

	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!(data->forks))
		return (init_error(data));
	i = 0;
	while (i < data->num_of_philo)
	{
		res = init_fork();
		if (res)
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
