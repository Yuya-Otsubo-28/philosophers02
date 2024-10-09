/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:10:48 by yotsubo           #+#    #+#             */
/*   Updated: 2024/10/09 13:10:48 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	my_usleep(long long time)
{
	long long	now;
	long long	end_time;

	end_time = get_utime() + time;
	while (1)
	{
		now = get_utime();
		if (now >= end_time)
			break ;
		usleep(1);
	}
}
