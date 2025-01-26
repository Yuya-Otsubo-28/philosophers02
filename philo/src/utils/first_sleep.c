/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:02:52 by yuotsubo          #+#    #+#             */
/*   Updated: 2025/01/26 15:05:38 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	first_sleep(t_philo *philo, int	type)
{
	if (type == EVEN)
	{
		my_usleep((philo->data->time_to_eat + philo->data->time_to_eat / \
				(philo->data->num_of_philo / 2) * (philo->id / 2)) * 1e3 + 10);
	}
	else
	{
		my_usleep((philo->data->time_to_eat * 1e3 / \
			(philo->data->num_of_philo / 2)) * (philo->id / 2));
	}
}
