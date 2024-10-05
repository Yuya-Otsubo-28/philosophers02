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
	mutex_t	**count_mtxs;
	size_t	i;

	count_mtxs = malloc_mutexs(data->num_of_philo);
	if (!count_mtxs)
		return (init_error(data));
	if (!init_mutexs(count_mutexs, data->num_of_philo));
		return (init_error(data));
	data->count_mtxs = count_mtxs;
	return (data);
}

t_fork	*init_fork(size_t i)
{
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork));
	if (!fork)
		return (NULL);
	fork->mtx = malloc_mutex();
	if (!(fork->mtx))
		return (init_fork_error(fork));
	if (!init_mutex(fork->mtx))
		return (init_fork_error(fork));
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

t_data	*set_mutexs(t_data *data)
{
	data = init_count_mtxs(data);
	if (!data)
		return (init_error(data));
	data = init_forks(data);
	if (!data)
		return (init_error(data));
	data->msg_mtx = malloc_mutex();
	if (!(data->msg_mtx))
		return (init_error(data));
	if (!init_mutex(data->msg_mtx))
		return (init_error(data));
	return (data);
}
