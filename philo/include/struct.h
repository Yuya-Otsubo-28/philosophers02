#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef int t_bool;

typedef struct s_fork {
	pthread_mutex_t	mtx;
	size_t			id;
}	t_fork ;

// TODO: philoの中にdataを持たせる。
// TODO: philoの中にmsg_mtxを持たせる。
// TODO: philoの中にlast_eatを持たせる。
// TODO: philoの中にtime_to_sleepなど不変でよく参照する変数を追加する。
typedef struct s_philo {
	size_t			id;
	t_fork			*right;
	t_fork			*left;
	pthread_mutex_t	*data_mtx;
	int				eat_count;
}	t_philo ;

// TODO: pthread_mutex_tをラップした構造体を定義し、mutexが初期化されたものかどうかを判定できるようにする。
typedef struct s_data {
	t_philo			**philos;
	t_fork			**forks;
	pthread_t		*threads;
	pthread_t		monitor;
	pthread_mutex_t	data_mtx;
	int				num_of_philo;
	int				time_to_sleep;
	int				time_to_die;
	int				time_to_eat;
	int				must_eat;
}	t_data ;

#endif