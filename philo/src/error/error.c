/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:36:39 by yotsubo           #+#    #+#             */
/*   Updated: 2024/09/30 20:36:39 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_data	*init_error(t_data *data)
{
	cleanup_data(data);
	return (NULL);
}

int	main_error(t_data *data, int errnum)
{
	cleanup_data(data);
	printf("ERROR\n");
	return (EXIT_FAILURE);
}
