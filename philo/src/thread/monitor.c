/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 03:20:08 by yotsubo           #+#    #+#             */
/*   Updated: 2024/10/06 03:20:08 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	set_start(t_data *data)
{
	pthread_mutex_lock(&(data->flag_mtx->mtx));
	data->is_start = TRUE;
	pthread_mutex_unlock(&(data->flag_mtx->mtx));
}

static void	*set_finish(t_data *data)
{
	pthread_mutex_lock(&(data->flag_mtx->mtx));
	data->is_finish = TRUE;
	pthread_mutex_unlock(&(data->flag_mtx->mtx));
	return (NULL);
}

void	*monitor(void *arg)
{
	t_data	*data;
	size_t	i;
	size_t	totla_eat;

	data = (t_data *)arg;
	set_start(data);
	while (1)
	{
		i = 0;
		totla_eat = 0;
		while (i < (size_t)data->num_of_philo)
		{
			pthread_mutex_lock(&(data->count_mtxs[i]->mtx));
			if (data->philos[i]->is_dead)
			{
				pthread_mutex_unlock(&(data->count_mtxs[i]->mtx));
				return (set_finish(data));
			}
			if (data->philos[i]->eat_count >= data->must_eat)
				totla_eat++;
			pthread_mutex_unlock(&(data->count_mtxs[i]->mtx));
			i++;
		}
		if (totla_eat == (size_t)data->num_of_philo)
			return (set_finish(data));
	}
}