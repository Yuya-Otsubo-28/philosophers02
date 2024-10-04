#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef int t_bool;

typedef struct s_fork {
	pthread_mutex_t	mtx;
	size_t			id;
}	t_fork ;

// TODO: philoの中にmsg_mtxを持たせる。
// TODO: philoの中にlast_eatを持たせる。
// TODO: philoの中にtime_to_sleepなど不変でよく参照する変数を追加する。
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
// TODO: is_start, is_finishをdataに含める。
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
}	t_data ;

#endif