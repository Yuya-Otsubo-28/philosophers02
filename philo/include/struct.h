#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <sys/time.h>

typedef int t_bool;

typedef struct s_mutex {
	pthread_mutex_t mtx;
	t_bool			is_init;
}	t_mutex;

typedef struct s_fork {
	t_mutex	mtx;
	size_t	id;
}	t_fork ;

typedef struct s_time {
	time_t		tv_sec;
	suseconds_t	tv_usec;
}	t_time;

typedef struct s_philo {
	t_data	*data;
	size_t	id;
	t_fork	*right;
	t_fork	*left;
	t_mutex	*count_mtx;
	t_mutex	*msg_mtx;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		eat_count;
	long long	start_time;
	long long	last_eat;
}	t_philo ;

typedef struct s_data {
	t_philo		**philos;
	t_fork		**forks;
	pthread_t	*threads;
	pthread_t	monitor;
	t_mutex		**count_mtxs;
	t_mutex		*msg_mtx;
	t_mutex		*flag_mtx;
	int			num_of_philo;
	int			must_eat;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	t_bool		is_start;
	t_bool		is_finish;
}	t_data ;

#endif