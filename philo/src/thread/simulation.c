/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:53:14 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/12/20 00:37:34 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	drop_forks(t_fork *first, t_fork *second)
{
	if (first)
		pthread_mutex_unlock(&(first->my_mtx->mtx));
	if (second)
		pthread_mutex_unlock(&(second->my_mtx->mtx));
	return (TRUE);
}

t_bool	is_finish(t_philo *philo)
{
	pthread_mutex_lock(&(philo->flag_mtx->mtx));
	if (philo->data->is_finish)
	{
		pthread_mutex_unlock(&(philo->flag_mtx->mtx));
		return (TRUE);
	}
	pthread_mutex_unlock(&(philo->flag_mtx->mtx));
	return (FALSE);
}

static void	even_simulation(t_philo *philo)
{
	while (1)
	{
		taking_fork(philo, RIGHT);
		if (is_finish(philo) && drop_forks(philo->right, NULL))
			break ;
		taking_fork(philo, LEFT);
		if (is_finish(philo) && drop_forks(philo->left, philo->right))
			break ;
		eating(philo);
		if (is_finish(philo) && drop_forks(philo->left, philo->right))
			break ;
		drop_forks(philo->left, philo->right);
		if (is_finish(philo))
			break ;
		sleeping(philo);
		if (is_finish(philo))
			break ;
		thinking(philo);
		if (is_finish(philo))
			break ;
	}
}

static void	odd_simulation(t_philo *philo)
{
	while (1)
	{
		thinking(philo);
		if (is_finish(philo))
			break ;
		taking_fork(philo, LEFT);
		if (is_finish(philo) && drop_forks(philo->left, NULL))
			break ;
		taking_fork(philo, RIGHT);
		if (is_finish(philo) && drop_forks(philo->right, philo->left))
			break ;
		eating(philo);
		if (is_finish(philo) && drop_forks(philo->right, philo->left))
			break ;
		drop_forks(philo->right, philo->left);
		if (is_finish(philo))
			break ;
		sleeping(philo);
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
		pthread_mutex_lock(&(philo->flag_mtx->mtx));
		if (philo->data->is_start)
		{
			philo->last_eat = philo->data->start_time;
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
