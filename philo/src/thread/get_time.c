/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 00:58:15 by yotsubo           #+#    #+#             */
/*   Updated: 2024/10/06 00:58:15 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long long	get_time(void)
{
	long long	res;
	t_time		time;

	gettimeofday(&time, NULL);
	res = time.tv_sec * 1e3;
	res += time.tv_usec / 1e3;
	return (res);
}
