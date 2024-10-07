/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:36:39 by yotsubo           #+#    #+#             */
/*   Updated: 2024/09/30 20:36:39 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_data	*init_error(t_data *data)
{
	if (!data)
		return (NULL);
	cleanup_data(data, 0);
	return (NULL);
}

t_fork	*init_fork_error(t_fork *fork)
{
	if (!fork)
		return (NULL);
	cleanup_fork(fork);
	return (NULL);
}

t_bool	launch_threads_error(t_data *data, size_t i)
{
	if (!data)
		return (FALSE);
	cleanup_data(data, i);
	return (FALSE);
}

int	main_error(t_data *data)
{
	if (data)
		cleanup_data(data, 0);
	printf("ERROR\n");
	return (EXIT_FAILURE);
}

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

