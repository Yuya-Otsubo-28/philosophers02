/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:53:14 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/10/02 13:15:28 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	print_status(philo, TAKE);
}

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_status(philo, TAKE);
}

void	eat(t_philo *philo)
{
	print_status(philo, EAT);
	usleep();
}

void	sleep(t_philo *philo)
{
	print_status(philo, SLEEP);
	usleep();
}

void	think(t_philo *philo)
{
	print_status(philo, THINK);
	usleep();
}

t_bool	is_finish(t_philo *philo)
{
	pthread_mutex_lock(philo->data_mtx);
	if (philo->data->is_finish)
	{
		pthread_mutex_unlock(philo->data_mtx);
		return (TRUE);
	}
	pthread_mutex_unlock(philo->data_mtx);
}

void	even_simulation(t_philo *philo)
{
	while (1)
	{
		take_right_fork(philo);
		if (is_finish(philo))
			break ;
		take_left_fork(philo);
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

void	odd_simulation(t_philo *philo)
{
	while (1)
	{
		take_left_fork(philo);
		if (is_finish(philo))
			break ;
		take_right_fork(philo);
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

void	*simulation_start(void *arg)
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
		even_simulation(philo);
	else
		odd_simulation(philo);
	return (NULL);
}