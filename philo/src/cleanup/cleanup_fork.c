/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:21:28 by yotsubo           #+#    #+#             */
/*   Updated: 2024/12/19 15:21:54 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_fork(t_fork *fork)
{
	if (!fork)
		return ;
	cleanup_mutex(fork->my_mtx);
	free(fork);
}

void	cleanup_forks(t_fork **forks, int num_of_philo)
{
	size_t	i;

	if (!forks)
		return ;
	i = 0;
	while (i < (size_t)num_of_philo && forks[i])
		cleanup_fork(forks[i++]);
	free(forks);
}
