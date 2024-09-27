#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef struct s_philo {
	pthread_t	right;
	pthread_t	left;
	int			eat_count;
}	t_philo ;

typedef struct s_data {
	t_philo		**philos;
	pthread_t	*forks;
	int			time_to_death;
	int			time_for_eat;
	int			time_for_sleep;
	int			must_eat;
}	t_data ;

#endif