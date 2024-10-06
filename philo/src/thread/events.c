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

void	take_fork(t_philo *philo, int hand)
{
	if (hand == RIGHT)
		pthread_mutex_lock(&(philo->right->mtx));
	else if (hand == LEFT)
		pthread_mutex_lock(&(philo->left->mtx));
	print_status(philo, TAKE);
}

void	die(t_philo *philo, long long now)
{
	pthread_mutex_lock(&(philo->msg_mtx->mtx));
	printf("%d %zu died\n", now - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&(philo->msg_mtx->mtx));
}

void	eat(t_philo *philo)
{
	print_status(philo, EAT);
	usleep(philo->time_to_eat * 1e3);
}

void	sleep(t_philo *philo)
{
	print_status(philo, SLEEP);
	usleep(philo->time_to_sleep * 1e3);
}

void	think(t_philo *philo)
{
	print_status(philo, THINK);
	usleep(100);
}
