/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:22:43 by yotsubo           #+#    #+#             */
/*   Updated: 2024/12/19 15:22:43 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_data(t_data *data, size_t i)
{
	if (!data)
		return ;
	cleanup_philos(data->philos, data->num_of_philo);
	cleanup_forks(data->forks, data->num_of_philo);
	cleanup_threads(data->threads, i);
	cleanup_mutex(data->msg_mtx);
	cleanup_mutexs(data->count_mtxs, data->num_of_philo);
	free(data);
}
