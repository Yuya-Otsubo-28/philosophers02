/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_until_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:48:22 by yotsubo           #+#    #+#             */
/*   Updated: 2024/10/07 13:48:22 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleep_until_death(t_philo *philo, long long time)
{
	long long	now;
	long long	death_time;

	death_time = philo->last_eat + philo->time_to_die;
	while (1)
	{
		now = get_mtime();
		if (now >= time)
			break ;
		if (now >= death_time)
			return (DEAD);
		usleep(1);
	}
	return (ALIVE);
}
