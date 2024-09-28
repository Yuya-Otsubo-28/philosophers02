#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef struct s_fork {
	pthread_mutex_t	fork;
	int				id;
}	t_fork ;

typedef struct s_philo {
	t_fork	*right;
	t_fork	*left;
	int		eat_count;
}	t_philo ;

typedef struct s_data {
	t_philo	**philos;
	t_fork	**forks;
	int		num_of_philo;
	int		time_for_sleep;
	int		time_to_death;
	int		time_for_eat;
	int		must_eat;
}	t_data ;

#endif