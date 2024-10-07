/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 03:19:15 by yotsubo           #+#    #+#             */
/*   Updated: 2024/10/06 03:19:15 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	taking_fork(t_philo *philo, int hand)
{
	if (hand == RIGHT)
		pthread_mutex_lock(&(philo->right->my_mtx->mtx));
	else if (hand == LEFT)
		pthread_mutex_lock(&(philo->left->my_mtx->mtx));
	if (get_time() >= philo->last_eat + philo->time_to_die)
	{
		died(philo, get_time());
		return ;
	}
	print_status(philo, TAKE);
}

void	died(t_philo *philo, long long now)
{
	pthread_mutex_lock(&(philo->count_mtx->mtx));
	philo->is_dead = TRUE;
	pthread_mutex_unlock(&(philo->count_mtx->mtx));
	pthread_mutex_lock(&(philo->msg_mtx->mtx));
	if (!(philo->is_dead) && is_finish(philo))
	{
		pthread_mutex_unlock(&(philo->msg_mtx->mtx));
		return ;
	}
	printf(RED);
	printf("%lld %zu died\n", now - philo->data->start_time, philo->id);
	printf(RESET);
	pthread_mutex_unlock(&(philo->msg_mtx->mtx));
}

void	eating(t_philo *philo)
{
	print_status(philo, EAT);
	if (sleep_until_death(philo, get_time() + philo->time_to_eat) == DEAD)
		died(philo, get_time());
	// usleep(philo->time_to_eat * 1e3);
}

void	sleeping(t_philo *philo)
{
	print_status(philo, SLEEP);
	if (sleep_until_death(philo, get_time() + philo->time_to_sleep) == DEAD)
		died(philo, get_time());
	// usleep(philo->time_to_sleep * 1e3);
}

void	thinking(t_philo *philo)
{
	print_status(philo, THINK);
	usleep(100);
}
