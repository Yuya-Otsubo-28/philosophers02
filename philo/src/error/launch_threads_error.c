/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:49:39 by yotsubo           #+#    #+#             */
/*   Updated: 2024/12/20 00:49:55 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	launch_threads_error(t_data *data, size_t i)
{
	if (!data)
		return (FALSE);
	cleanup_data(data, i);
	return (FALSE);
}
