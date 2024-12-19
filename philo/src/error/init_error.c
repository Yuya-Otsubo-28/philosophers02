/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:47:53 by yotsubo           #+#    #+#             */
/*   Updated: 2024/12/20 00:48:13 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
