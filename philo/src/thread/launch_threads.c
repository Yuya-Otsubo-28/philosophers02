/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 07:37:12 by yotsubo           #+#    #+#             */
/*   Updated: 2024/10/01 07:37:12 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&(philo->flag_mtx->mtx));
		if (philo->data->is_start)
		{
			philo->last_eat = philo->data->start_time;
			pthread_mutex_unlock(&(philo->flag_mtx->mtx));
			break ;
		}
		pthread_mutex_unlock(&(philo->flag_mtx->mtx));
	}
	taking_fork(philo, LEFT);
	while (1)
	{
		if (is_finish(philo))
		{
			drop_forks(philo->left, NULL);
			break ;
		}
	}
	return (NULL);
}

static t_bool	only_one_philo(t_data *data)
{
	if (pthread_create(&(data->threads[0]), NULL, one_philo, data->philos[0]))
		return (launch_threads_error(data, 0));
	if (pthread_create(&(data->monitor), NULL, monitor, data))
		return (launch_threads_error(data, 0));
	if (pthread_join(data->monitor, NULL) < 0)
		return (launch_threads_error(data, 0));
	if (pthread_join(data->threads[0], NULL) < 0)
		return (launch_threads_error(data, 0));
	return (TRUE);
}

t_bool	launch_threads(t_data *data)
{
	size_t	i;

	if (!data->num_of_philo)
		return (launch_threads_error(data, 0));
	if (data->num_of_philo == 1)
		return (only_one_philo(data));
	i = 0;
	while (i < (size_t)data->num_of_philo)
	{
		if (pthread_create(&(data->threads[i]), NULL, \
			simulation_start, data->philos[i]))
			return (launch_threads_error(data, i));
		i++;
	}
	if (pthread_create(&(data->monitor), NULL, monitor, data))
		return (launch_threads_error(data, i));
	if (pthread_join(data->monitor, NULL) < 0)
		return (launch_threads_error(data, i));
	while (i-- > 0)
	{
		if (pthread_join(data->threads[i], NULL) < 0)
			return (launch_threads_error(data, i));
	}
	return (TRUE);
}
