/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:36:20 by yotsubo           #+#    #+#             */
/*   Updated: 2024/09/30 20:36:20 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	cleanup_philos(t_philo **philos, int num_of_philo)
{
	size_t	i;

	if (!philos)
		return ;
	i = 0;
	while (i < (size_t)num_of_philo && philos[i])
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
	while (i < (size_t)num_of_philo && forks[i])
		cleanup_fork(forks[i++]);
	free(forks);
}

void	cleanup_threads(pthread_t *threads, size_t to_join)
{
	size_t	i;

	i = 0;
	while (i < to_join)
		pthread_join(threads[i], NULL);
	free(threads);
}

void	cleanup(t_data *data)
{
	pthread_mutex_destroy(&(data->data_mtx));
	pthread_mutex_destroy(&(data->msg_mtx));
}

void	cleanup_data(t_data *data, size_t i)
{
	if (!data)
		return ;
	cleanup_philos(data->philos, data->num_of_philo);
	cleanup_forks(data->forks, data->num_of_philo);
	cleanup_threads(data->threads, i);
	cleanup_mutexs(data);
	free(data);
}
