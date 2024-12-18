/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mutex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:28:51 by yotsubo           #+#    #+#             */
/*   Updated: 2024/10/04 09:28:51 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mutex	*malloc_mutex(void)
{
	t_mutex	*mutex;

	mutex = (t_mutex *)malloc(sizeof(t_mutex));
	if (!mutex)
		return (NULL);
	mutex->is_init = FALSE;
	return (mutex);
}

t_mutex	**malloc_mutexs(size_t num)
{
	size_t	i;
	t_mutex	**mutexs;

	mutexs = (t_mutex **)malloc(sizeof(t_mutex *) * num);
	if (!mutexs)
		return (mutexs_error(mutexs, num));
	memset(mutexs, 0, sizeof(t_mutex *) * num);
	i = 0;
	while (i < num)
	{
		mutexs[i] = malloc_mutex();
		if (!mutexs[i])
			return (mutexs_error(mutexs, num));
		mutexs[i]->is_init = FALSE;
		i++;
	}
	return (mutexs);
}

t_mutex	*init_mutex(t_mutex *mutex)
{
	if (pthread_mutex_init(&(mutex->mtx), NULL) < 0)
		return (mutex_error(mutex));
	mutex->is_init = TRUE;
	return (mutex);
}

t_mutex	**init_mutexs(t_mutex **mutexs, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		mutexs[i] = init_mutex(mutexs[i]);
		if (!mutexs[i])
			return (mutexs_error(mutexs, num));
		i++;
	}
	return (mutexs);
}
