/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 07:37:12 by yotsubo           #+#    #+#             */
/*   Updated: 2024/10/01 07:37:12 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_bool	make_threads(t_data *data)
{
	size_t	i;

	if (!data->num_of_philo)
		return (FALSE);
	if (data->num_of_philo == 1)
		return (only_one_philo(data));
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_create(&(data->threads[i]), NULL, philo_life, data->philos[i]))
			return (make_threads_error(data));
		i++;
	}
}
