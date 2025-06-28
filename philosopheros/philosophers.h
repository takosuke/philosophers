#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philosopher
{
	int	id;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_t	thread_id;
	int		last_ate_time;
	int		times_to_eat;
} t_philosopher;

typedef struct s_restaurant
{
	int	num_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
	t_philosopher *philosophers;
	pthread_mutex_t	*forks;
}	t_restaurant;

int	ft_atoi(const char *str);
void	init_philosophers(t_restaurant *restaurant);
void	init_forks(t_restaurant *restaurant);
t_restaurant init_restaurant(int argc, char **argv);

#endif
