/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:22:08 by yotsubo           #+#    #+#             */
/*   Updated: 2024/12/19 15:22:38 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_threads(pthread_t *threads, size_t to_join)
{
	size_t	i;

	i = 0;
	while (i < to_join)
		pthread_join(threads[i], NULL);
	free(threads);
}
