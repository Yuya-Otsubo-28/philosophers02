/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:28:45 by yotsubo           #+#    #+#             */
/*   Updated: 2024/12/19 15:28:45 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <sys/time.h>

typedef int				t_bool;
typedef struct timeval	t_time;

typedef struct s_mutex {
	pthread_mutex_t	mtx;
	t_bool			is_init;
}	t_mutex;

typedef struct s_fork {
	t_mutex	*my_mtx;
	size_t	id;
}	t_fork;

typedef struct s_philo {
	struct s_data	*data;
	size_t			id;
	t_fork			*right;
	t_fork			*left;
	t_mutex			*count_mtx;
	t_mutex			*msg_mtx;
	t_mutex			*flag_mtx;
	t_bool			is_dead;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count;
	long long		last_eat;
}	t_philo;

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
	long long	start_time;
	t_bool		is_start;
	t_bool		is_finish;
}	t_data;

#endif