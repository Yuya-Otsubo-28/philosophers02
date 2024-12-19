/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:49:12 by yotsubo           #+#    #+#             */
/*   Updated: 2024/12/20 00:49:12 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main_error(t_data *data)
{
	if (data)
		cleanup_data(data, 0);
	printf("ERROR\n");
	return (EXIT_FAILURE);
}
