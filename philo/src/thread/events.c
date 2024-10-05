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

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right->mtx));
	print_status(philo, TAKE);
}

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left->mtx));
	print_status(philo, TAKE);
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
