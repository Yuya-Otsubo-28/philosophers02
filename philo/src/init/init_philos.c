/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:24:26 by yotsubo           #+#    #+#             */
/*   Updated: 2024/10/04 09:24:26 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static t_philo	*init_philo(t_data *data, size_t i)
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
	philo->count_mtx = data->count_mtxs[i];
	philo->msg_mtx = data->msg_mtx;
	philo->flag_mtx = data->flag_mtx;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->is_dead = FALSE;
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
