#include "../include/struct.h"
#include <pthread.h>
#include <limits.h>

t_bool	is_invalid_input(char *nbrp)
{
	long long	lln;
	size_t		i;

	if (!nbrp)
		return (TRUE);
	if (ft_strlen(nbrp) > INT_MAX_DIGIT)
		return (TRUE);
	lln = 0LL;
	i = 0;
	while (nbrp[i])
	{
		if (ft_isdigit(nbrp[i]))
			return (TRUE);
		lln *= 10;
		lln += nbrp[i] - '0';
		i++;
	}
	if (lln > INT_MAX)
		return (TRUE);
	return (FALSE);
}

t_data	*init_num_datas(t_data *data, char **argv)
{
	if (is_invalid_input(argv[1]))
		return (init_error(data));
	data->num_of_philo = ft_atoi(argv[1]);
	if (is_invalid_input(argv[2]))
		return (init_error(data));
	data->time_to_die = ft_atoi(argv[2]);
	if (is_invalid_input(argv[3]))
		return (init_error(data));
	data->time_to_eat = ft_atoi(argv[3]);
	if (is_invaild_input(argv[4]))
		return (init_error(data));
	data->time_to_sleep = ft_atoi(argv[4]);
	return (data);
}

t_philo	*init_philo(t_data *data, int i)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->right = data->forks[i];
	if (i == 0)
		philo->left = data->forks[data->num_of_philo - 1];
	else
		philo->left = data->forks[i - 1];
	philo->eat_count = 0;
	return (philo);
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
		data->philos[i] = init_philo(i);
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
		data->forks[i] = init_fork(data, i);
		if (!(data->forks[i]))
			return (init_error(data));
		i++;
	}
	return (data);
}

t_data	*init_must_eat(t_data *data, int argc, char *argv[])
{
	if (argc != 6)
		return (data);
	if (is_invalid_input(argv[5]))
		return (init_error(data));
	data->must_eat = ft_itoa(argv[5]);
	return (data);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (data);
	memset(data, 0, sizeof(t_data));
	data = init_num_datas(data, argv);
	if (!data)
		return (NULL);
	data = init_forks(data);
	if (!data)
		return (NULL);
	data = init_philos(data);
	if (!data)
		return (NULL);
	data = init_must_eat(data, argc, argv);
	if (!data)
		return (NULL);
	return (data);
}


int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (1);
	data = init_data(argc, argv);
}