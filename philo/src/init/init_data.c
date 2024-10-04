/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:36:15 by yotsubo           #+#    #+#             */
/*   Updated: 2024/09/30 20:36:15 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static t_bool	is_invalid_input(char *nbrp)
{
	long long	lln;
	size_t		i;

	if (!nbrp)
		return (TRUE);
	if (ft_strlen(nbrp) > INT_MAX_DIGIT)
		return (TRUE);
	lln = 0LL;
	i = 0;
	while (nbrp[i])
	{
		if (!ft_isdigit(nbrp[i]))
			return (TRUE);
		lln *= 10;
		lln += nbrp[i] - '0';
		i++;
	}
	if (lln > INT_MAX)
		return (TRUE);
	return (FALSE);
}

static t_data	*init_num_datas(t_data *data, char **argv)
{
	if (is_invalid_input(argv[1]))
		return (init_error(data));
	data->num_of_philo = ft_atoi(argv[1]);
	if (is_invalid_input(argv[2]))
		return (init_error(data));
	data->time_to_die = ft_atoi(argv[2]);
	if (is_invalid_input(argv[3]))
		return (init_error(data));
	data->time_to_eat = ft_atoi(argv[3]);
	if (is_invalid_input(argv[4]))
		return (init_error(data));
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat = -1;
	return (data);
}

static t_data	*init_must_eat(t_data *data, int argc, char *argv[])
{
	if (argc != 6)
		return (data);
	if (is_invalid_input(argv[5]))
		return (init_error(data));
	data->must_eat = ft_atoi(argv[5]);
	return (data);
}

static t_data	*init_threads(t_data *data)
{
	data->threads = (pthread_t *)malloc(sizeof(pthread_t) * data->num_of_philo);
	if (!(data->threads))
		return (init_error(data));
	return (data);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (data);
	memset(data, 0, sizeof(t_data));
	data = init_num_datas(data, argv);
	if (!data)
		return (NULL);
	data = init_must_eat(data, argc, argv);
	if (!data)
		return (NULL);
	data = init_mutexs(data);
	if (!data)
		return (NULL);
	data = init_philos(data);
	if (!data)
		return (NULL);
	data = init_threads(data);
	if (!data)
		return (NULL);
	return (data);
}
