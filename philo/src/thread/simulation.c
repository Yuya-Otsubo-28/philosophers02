/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:53:14 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/10/06 15:45:45 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static t_bool	is_finish(t_philo *philo)
{
	pthread_mutex_lock(&(philo->flag_mtx->mtx));
	if (philo->data->is_finish)
	{
		pthread_mutex_unlock(&(philo->flag_mtx->mtx));
		return (TRUE);
	}
	pthread_mutex_unlock(&(philo->flag_mtx->mtx));
}

static void	even_simulation(t_philo *philo)
{
	while (1)
	{
		take_fork(philo, RIGHT);
		if (is_finish(philo))
			break ;
		take_fork(philo, LEFT);
		if (is_finish(philo))
			break ;
		eat(philo);
		if (is_finish(philo))
			break ;
		pthread_mutex_unlock(&(philo->left->mtx));
		pthread_mutex_unlock(&(philo->right->mtx));
		if (is_finish(philo))
			break ;
		sleep(philo);
		if (is_finish(philo))
			break ;
		think(philo);
		if (is_finish(philo))
			break ;
	}
}

static void	odd_simulation(t_philo *philo)
{
	while (1)
	{
		take_fork(philo, LEFT);
		if (is_finish(philo))
			break ;
		take_fork(philo, RIGHT);
		if (is_finish(philo))
			break ;
		eat(philo);
		if (is_finish(philo))
			break ;
		pthread_mutex_unlock(&(philo->right->mtx));
		pthread_mutex_unlock(&(philo->left->mtx));
		if (is_finish(philo))
			break ;
		sleep(philo);
		if (is_finish(philo))
			break ;
		think(philo);
		if (is_finish(philo))
			break ;
	}
}

void	*simulation_start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&(philo->flag_mtx->mtx))
		if (philo->data->is_start)
		{
			pthread_mutex_unlock(&(philo->flag_mtx->mtx));
			break ;
		}
		pthread_mutex_unlock(&(philo->flag_mtx->mtx));
	}
	if (philo->id % 2)
		even_simulation(philo);
	else
		odd_simulation(philo);
	return (NULL);
}
