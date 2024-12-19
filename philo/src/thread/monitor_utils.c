/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:18:56 by yotsubo           #+#    #+#             */
/*   Updated: 2024/12/20 00:19:53 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_all_philo_dead(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (size_t)data->num_of_philo)
		data->philos[i++]->is_dead = TRUE;
}

void	all_philos_mutex_lock(t_data *data, size_t num)
{
	size_t	i;

	i = 0;
	while (i < (size_t)data->num_of_philo)
	{
		if (i != num)
			pthread_mutex_lock(&(data->count_mtxs[i]->mtx));
		i++;
	}
}

void	all_philos_mutex_unlock(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (size_t)data->num_of_philo)
	{
		pthread_mutex_unlock(&(data->count_mtxs[i]->mtx));
		i++;
	}
}
