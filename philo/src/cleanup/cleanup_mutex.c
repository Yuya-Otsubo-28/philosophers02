/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:20:35 by yotsubo           #+#    #+#             */
/*   Updated: 2024/12/19 15:20:57 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_mutex(t_mutex *mutex)
{
	if (!mutex)
		return ;
	if (mutex->is_init)
		pthread_mutex_destroy(&(mutex->mtx));
	free(mutex);
}

void	cleanup_mutexs(t_mutex **mutexs, size_t num)
{
	size_t	i;

	if (!mutexs)
		return ;
	i = 0;
	while (i < num)
		cleanup_mutex(mutexs[i++]);
	free(mutexs);
}
