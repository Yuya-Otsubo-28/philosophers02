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

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (main_error(data, 0));
	data = init_data(argc, argv);
	if (!data)
		return (main_error(data, 0));
	launch_threads();
	cleanup(data);
	return (EXIT_SUCCESS);
}
