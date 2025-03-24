#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

//typedef struct philosopher_s philosopher_t;

typedef struct	s_fork
{
	int				id;
	pthread_mutex	fork;
}	t_fork;

typedef struct	s_philo
{
	int	id;
	t_fork		*l_fork;
	t_fork		*r_fork;
	pthread_t	thread_id;
	long		last_ate_time;
	long		times_to_eat;
} t_philo;

typedef struct	s_restaurant
{
	t_philo		*philosophers;
	t_fork		*forks;
	long		num_philosophers;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
}	t_restaurant;

#endif

