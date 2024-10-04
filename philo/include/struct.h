#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef int t_bool;

typedef struct s_mutex {
	pthread_mutex_t mtx;
	t_bool			is_init;
}	t_mutex;

typedef struct s_fork {
	t_mutex	mtx;
	size_t	id;
}	t_fork ;

typedef struct s_philo {
	t_data			*data;
	size_t			id;
	t_fork			*right;
	t_fork			*left;
	pthread_mutex_t	*count_mtx;
	pthread_mutex_t	*msg_mtx;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count;
	int				last_eat;
}	t_philo ;

// TODO: pthread_mutex_tをラップした構造体を定義し、mutexが初期化されたものかどうかを判定できるようにする。
typedef struct s_data {
	t_philo			**philos;
	t_fork			**forks;
	pthread_t		*threads;
	pthread_t		monitor;
	pthread_mutex_t	*count_mtxs;
	pthread_mutex_t	msg_mtx;
	int				num_of_philo;
	int				must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	t_bool			is_start;
	t_bool			is_finish;
}	t_data ;

#endif