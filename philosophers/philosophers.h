#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_fork
{
	int				id;
	pthread_mutex	fork;
}	t_fork;

typedef struct	s_philosopher
{
	int	id;
	t_fork		*l_fork;
	t_fork		*r_fork;
	pthread_t	thread_id;
	long		last_ate_time;
	long		times_to_eat;
} t_philosopher;

typedef struct s_restaurant
{
	long	num_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	max_meals;
	t_philosopher *philosophers;
	t_fork		*forks;
}	t_restaurant;

#endif
