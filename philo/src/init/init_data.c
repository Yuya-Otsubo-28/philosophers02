/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:36:15 by yotsubo           #+#    #+#             */
/*   Updated: 2024/09/30 20:36:15 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

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
		if (!ft_isdigit(nbrp[i]))
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
	if (is_invalid_input(argv[4]))
		return (init_error(data));
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat = -1;
	return (data);
}

t_philo	*init_philo(t_data *data, size_t i)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->id = i;
	philo->right = data->forks[i];
	if (i == 0)
		philo->left = data->forks[data->num_of_philo - 1];
	else
		philo->left = data->forks[i - 1];
	philo->eat_count = 0;
	philo->data = data;
	philo->count_mtx = &(data->count_mtxs[i]);
	philo->msg_mtx = &(data->msg_mtx);
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->must_eat = data->must_eat;
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
	while (i < (size_t)data->num_of_philo)
	{
		data->philos[i] = init_philo(data, i);
		if (!(data->philos[i]))
			return (init_error(data));
		i++;
	}
	return (data);
}

t_fork	*init_fork(size_t i)
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

	data->forks = (t_fork **)malloc(sizeof(t_fork *) * data->num_of_philo);
	if (!(data->forks))
		return (init_error(data));
	memset(data->forks, 0, sizeof(t_fork *) * data->num_of_philo);
	i = 0;
	while (i < (size_t)data->num_of_philo)
	{
		data->forks[i] = init_fork(i);
		if (!(data->forks[i]))
			return (init_error(data));
		i++;
	}
	return (data);
}

t_data	*init_threads(t_data *data)
{
	data->threads = (pthread_t *)malloc(sizeof(pthread_t) * data->num_of_philo);
	if (!(data->threads))
		return (init_error(data));
	return (data);
}

t_data	*init_must_eat(t_data *data, int argc, char *argv[])
{
	if (argc != 6)
		return (data);
	if (is_invalid_input(argv[5]))
		return (init_error(data));
	data->must_eat = ft_atoi(argv[5]);
	return (data);
}

t_data	*init_count_mtxs(t_data *data)
{
	pthread_mutex_t	*count_mtxs;
	size_t			i;

	count_mtxs = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!count_mtxs)
		return (init_error(data));
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_mutex_init(&(data->count_mtxs[i]), NULL))
			return (init_error(data));
		i++;
	}
	return (data);
}

t_data	*init_mutexs(t_data *data)
{
	data = init_count_mtxs(data);
	if (!data)
		return (init_error(data));
	data = init_forks(data);
	if (!data)
		return (init_error(data));
	if (pthread_mutex_init(&(data->msg_mtx), NULL))
		return (init_error(data));
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
	data = init_must_eat(data, argc, argv);
	if (!data)
		return (NULL);
	data = init_mutexs(data);
	if (!data)
		return (NULL);
	data = init_philos(data);
	if (!data)
		return (NULL);
	data = init_threads(data);
	if (!data)
		return (NULL);
	return (data);
}
