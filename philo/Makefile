# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 09:01:07 by yotsubo           #+#    #+#              #
#    Updated: 2024/09/27 09:01:07 by yotsubo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread #-g -fsanitize=address
SRCS		= ./src/cleanup/cleanup_data.c \
				./src/cleanup/cleanup_fork.c \
				./src/cleanup/cleanup_mutex.c \
				./src/cleanup/cleanup_philos.c \
				./src/cleanup/cleanup_threads.c \
				./src/error/init_error.c \
				./src/error/launch_threads_error.c \
				./src/error/main_error.c \
				./src/error/mutex_error.c \
				./src/init/init_data.c \
				./src/init/init_mutexs.c \
				./src/init/init_philos.c \
				./src/thread/events.c \
				./src/thread/get_time.c \
				./src/thread/launch_threads.c \
				./src/thread/monitor.c \
				./src/thread/monitor_utils.c \
				./src/thread/print_status.c \
				./src/thread/simulation.c \
				./src/utils/ft_atoi.c \
				./src/utils/ft_isdigit.c \
				./src/utils/ft_isspace.c \
				./src/utils/ft_strlen.c \
				./src/utils/my_mutex.c \
				./src/utils/sleep_until_death.c \
				./src/utils/my_usleep.c \
				./src/utils/first_sleep.c \
				./src/main.c
OBJS		= $(SRCS:.c=.o)
INCLUDES	= -I./include

all : $(NAME)

$(NAME) :$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
