/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:21:29 by yotsubo           #+#    #+#             */
/*   Updated: 2024/10/04 09:21:29 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static t_data	*init_count_mtxs(t_data *data)
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
