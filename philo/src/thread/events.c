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
	print_status(philo, TAKE);
}

void	eating(t_philo *philo)
{
	print_status(philo, EAT);
	my_usleep(philo->time_to_eat * 1e3);
}

void	sleeping(t_philo *philo)
{
	print_status(philo, SLEEP);
	my_usleep(philo->time_to_sleep * 1e3);
}

void	thinking(t_philo *philo)
{
	print_status(philo, THINK);
	my_usleep(500);
}
