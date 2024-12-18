/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 22:34:49 by yotsubo           #+#    #+#             */
/*   Updated: 2024/09/30 22:34:49 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = NULL;
	if (argc != 5 && argc != 6)
		return (main_error(data));
	data = init_data(argc, argv);
	if (!data)
		return (main_error(data));
	launch_threads(data);
	cleanup_data(data, 0);
	return (EXIT_SUCCESS);
}
