#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

struct s_restaurant;

typedef struct	s_philosopher
{
	struct s_restaurant *restaurant;
	int	id;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_t	thread_id;
	size_t		last_meal_time;
	int		times_eaten;
} t_philosopher;

typedef struct s_restaurant
{
	int	num_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
	int closed;
	size_t opening_time;
	t_philosopher *philosophers;
	pthread_mutex_t	*forks;
}	t_restaurant;


//UTILS
int	ft_atoi(const char *str);
size_t	get_current_time(void);
int	ft_usleep(size_t milliseconds);
//INIT
void	init_philosophers(t_restaurant *restaurant);
void	init_forks(t_restaurant *restaurant);
t_restaurant init_restaurant(int argc, char **argv);
void	open_restaurant(t_restaurant *restaurant);

#endif
