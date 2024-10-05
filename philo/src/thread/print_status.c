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

char	*make_message(int status)
{
	char	*message;

	if (status == TAKE)
		message = "has taken a fork";
	else if (status == EAT)
		message = "is eating";
	else if (status == SLEEP)
		message = "is sleepig";
	else if (status == THINK)
		message = "is thinking";
	else if (status == DIED)
		message = "died";
	return (message);
}

t_bool	print_status(t_philo *philo, int status)
{
	char	*message;
	int		now;

	message = make_message(status);
	time = get_time(philo);
	if (status == EAT)
		update_last_eat(philo);
	pthread_mutex_lock(philo->msg_mtx);
	printf("%d %zu %s\n", time, philo->id, message);
	pthread_mutex_unlock(philo->msg_mtx);
	wait_status(philo, status);
}
