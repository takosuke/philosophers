#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_restaurant
{
	long	num_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	max_meals;
}	t_restaurant;

#endif
