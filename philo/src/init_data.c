#include "../include/struct.h"

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (data);
	memset(data, 0, sizeof(t_data));
	data = init_philos(argv);
	if (!data)
		return (init_error(data));
	data = init_forks(argv);
	if (!data)
		return (init_error(data));
	data = init_time(argv);
	if (!data)
		return (init_error(data));
	data = init_must_eat(argc, argv);
	if (!data)
		return (init_error(data));
	return (data);
}