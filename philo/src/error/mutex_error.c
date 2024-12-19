/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:47:19 by yotsubo           #+#    #+#             */
/*   Updated: 2024/12/20 00:47:41 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mutex	*mutex_error(t_mutex *mutex)
{
	if (!mutex)
		return (NULL);
	cleanup_mutex(mutex);
	return (NULL);
}

t_mutex	**mutexs_error(t_mutex **mutexs, size_t num)
{
	if (!mutexs)
		return (NULL);
	cleanup_mutexs(mutexs, num);
	return (NULL);
}
