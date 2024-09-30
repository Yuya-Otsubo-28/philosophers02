#include "../include/struct.h"
#include "../include/prototype.h"
#include <stdio.h>

static void	print_data(t_data *data)
{
	printf("-----data----\n");
	printf("num_of_philo: %d\n", data->num_of_philo);
	printf("time_to_die: %d\n", data->time_to_die);
	printf("time_to_sleep: %d\n", data->time_to_sleep);
	printf("time_to_eat: %d\n", data->time_to_eat);
	printf("must_eat: %d\n", data->must_eat);

	printf("-----philo------\n");
	for (size_t i = 0; i < data->num_of_philo; i++)
	{
		t_philo	*philo = data->philos[0];
		printf("philo[%zu]'s id: %d\n", i, philo->id);
		printf("philo[%zu]'s eat_count: %d\n", i, philo->eat_count);
		printf("philo[%zu]'s right: %p\n", i, philo->right);
		printf("philo[%zu]'s left: %dp\n", i, philo->left);
		printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (1);
	data = init_data(argc, argv);
	print_data(data);
	cleanup_data(data);
	return (0);
}