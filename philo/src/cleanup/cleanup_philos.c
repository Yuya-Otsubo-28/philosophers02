/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:22:59 by yotsubo           #+#    #+#             */
/*   Updated: 2024/12/19 15:23:20 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_philos(t_philo **philos, int num_of_philo)
{
	size_t	i;

	if (!philos)
		return ;
	i = 0;
	while (i < (size_t)num_of_philo && philos[i])
		free(philos[i++]);
	free(philos);
}
