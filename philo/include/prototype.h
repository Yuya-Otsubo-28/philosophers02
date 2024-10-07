/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:32:20 by yotsubo           #+#    #+#             */
/*   Updated: 2024/09/30 17:32:20 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define ifndef PROTOTYPE_H

# include "struct.h"

// cleanup.c

void	cleanup_data(t_data *data, size_t i);

void	cleanup_threads(pthread_t *threads, size_t to_join);

void	cleanup_forks(t_fork **forks, int num_of_philo);

void	cleanup_fork(t_fork *fork);

void	cleanup_philos(t_philo **philos, int num_of_philo);

void	cleanup_mutexs(t_mutex **mutexs, size_t num);

void	cleanup_mutex(t_mutex *mutex);

// error.c

int	main_error(t_data *data);

t_bool	launch_threads_error(t_data *data, size_t i);

t_fork	*init_fork_error(t_fork *fork);

t_data	*init_error(t_data *data);

t_mutex	**mutexs_error(t_mutex **mutexs, size_t num);

t_mutex	*mutex_error(t_mutex *mutex);

// init_data.c

t_data	*init_data(int argc, char **argv);

// init_mutexs.c

t_data	*set_mutexs(t_data *data);

// init_philos.c

t_data *init_philos(t_data *data);

// events.c

void	taking_fork(t_philo *philo, int hand);

void	died(t_philo *philo, long long now);

void	eating(t_philo *philo);

void	sleeping(t_philo *philo);

void	thinking(t_philo *philo);

// get_time.c

long long	get_time(void);

// launch_threads.c

t_bool	launch_threads(t_data *data);

// monitor.c

void	*monitor(void *arg);

// print_status.c

void	print_status(t_philo *philo, int status);

// simulation.c

t_bool	is_finish(t_philo *philo);

void	*simulation_start(void *arg);

// utils

int	ft_atoi(const char *nptr);

int	ft_isdigit(int c);

int	ft_isspace(char c);

size_t	ft_strlen(const char *s);

t_mutex	*init_mutex(t_mutex *mutex);

t_mutex	**init_mutexs(t_mutex **mutexs, size_t num);

t_mutex	*malloc_mutex(void);

t_mutex	**malloc_mutexs(size_t num);

int		sleep_until_death(t_philo *philo, long long time);

#endif