#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

# define FALSE 0
# define TRUE 1
# define INT_MAX_DIGIT 10

typedef int t_bool;

typedef struct s_fork {
	pthread_mutex_t	mtx;
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
	int		time_to_sleep;
	int		time_to_die;
	int		time_to_eat;
	int		must_eat;
}	t_data ;

#endif