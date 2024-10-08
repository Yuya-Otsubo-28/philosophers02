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

static t_bool	update_last_eat(t_philo *philo, long long now)
{
	pthread_mutex_lock(&(philo->count_mtx->mtx));
	philo->last_eat = now;
	philo->eat_count++;
	pthread_mutex_unlock(&(philo->count_mtx->mtx));
	return (TRUE);
}

static char	*make_message(int status)
{
	char	*message;

	if (status == TAKE)
		message = "has taken a fork";
	else if (status == EAT)
	{
		printf(YELLOW);
		message = "is eating";
	}
	else if (status == SLEEP)
	{
		printf(BLUE);
		message = "is sleeping";
	}
	else if (status == THINK)
	{
		printf(GREEN);
		message = "is thinking";
	}
	return (message);
}

void	print_status(t_philo *philo, int status)
{
	char		*message;
	long long	now;

	now = get_time();
	if (status == EAT)
		update_last_eat(philo, now);
	pthread_mutex_lock(&(philo->msg_mtx->mtx));
	message = make_message(status);
	if (is_finish(philo))
	{
		pthread_mutex_unlock(&(philo->msg_mtx->mtx));
		return ;
	}
	printf("%lld %zu %s\n", now - philo->data->start_time, philo->id, message);
	printf(RESET);
	pthread_mutex_unlock(&(philo->msg_mtx->mtx));
}
