/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:53:14 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/01/26 15:06:56 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	drop_forks(t_fork *first, t_fork *second)
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
	thinking(philo);
	if (philo->data->num_of_philo % 2)
		first_sleep(philo, EVEN);
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
	thinking(philo);
	if (philo->data->num_of_philo % 2)
		first_sleep(philo, ODD);
	else
		my_usleep(2000);
	while (1)
	{
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
		thinking(philo);
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
		odd_simulation(philo);
	else
		even_simulation(philo);
	return (NULL);
}
