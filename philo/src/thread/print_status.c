/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:27:16 by yotsubo           #+#    #+#             */
/*   Updated: 2024/10/02 13:27:16 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

char	*make_message(t_philo *philo, int status)
{
	char	*message;
}

void	print_status(t_philo *philo, int status)
{
	char	*message;

	message = make_message(philo, status);
	pthread_mutex_lock(philo->msg_mtx);
	printf("%s\n", message);
	pthread_mutex_unlock(philo->msg_mtx);
	wait_status(philo, status);
	free(message);
}
