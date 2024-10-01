/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:53:14 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/10/01 14:23:03 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	even_simu(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->right);
		// forkとたよ
		if (is_finish(philo))
			break ;
		pthread_mutex_lock(philo->left);
		// forkとたよ
		if (is_finish(philo))
			break ;
		eat(philo);
		if (is_finish(philo))
			break ;
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
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

void	odd_simu(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->left);
		// forkとたよ
		if (is_finish(philo))
			break ;
		pthread_mutex_lock(philo->right);
		// forkとたよ
		if (is_finish(philo))
			break ;
		eat(philo);
		if (is_finish(philo))
			break ;
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
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

void	*simu_start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->data_mtx)
		if (philo->data->go_flag)
		{
			pthread_mutex_unlock(philo->data_mtx);
			break ;
		}
		pthread_mutex_unlock(philo->data_mtx);
	}
	if (philo->id % 2)
		even_simu(philo);
	else
		odd_simulation(philo);
	return (NULL);
}