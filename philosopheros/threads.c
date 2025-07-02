#include "philosophers.h"

void	eat(t_philosopher *philosopher)
{
	size_t	eat_time;

	eat_time = get_current_time() - philosopher->restaurant->opening_time;
	if (eat_time > philosopher->last_meal_time + philosopher->restaurant->time_to_die)
		philosopher->restaurant->closed = 1;
	pthread_mutex_lock(philosopher->l_fork);
	printf("%zu %d has taken a fork\n", get_current_time() - philosopher->restaurant->opening_time, philosopher->id); // TODO timestamp, philosopher id?
	pthread_mutex_lock(philosopher->r_fork);
	printf("%zu %d has taken a fork\n", get_current_time() - philosopher->restaurant->opening_time, philosopher->id); // TODO timestamp, philosopher id?
	philosopher->times_eaten++;
	philosopher->last_meal_time = get_current_time() - philosopher->restaurant->opening_time;
	if (philosopher->times_eaten == philosopher->restaurant->max_meals)
		philosopher->restaurant->closed = 1;
	printf("%d is eating\n", philosopher->id); // TODO timestamp, philosopher id?
	// TODO set a flag that this philosopher is eating?but what for?
	ft_usleep(philosopher->restaurant->time_to_eat);
	pthread_mutex_unlock(philosopher->l_fork);
	pthread_mutex_unlock(philosopher->r_fork);
}

void	powernap(t_philosopher *philosopher)
{
	printf("philosopher %d is sleeping\n", philosopher->id);
	ft_usleep(philosopher->restaurant->time_to_sleep);
}

void	philosophize(t_philosopher *philosopher)
{
	printf("philosopher %d is thinking\n", philosopher->id);
}

void	*philosophical_routine(void *philosopher_ptr)
{
	t_philosopher	*philosopher;
	philosopher = (t_philosopher *)philosopher_ptr;
	printf("philosopher %d at the table\n", philosopher->id);
	ft_usleep(philosopher->id);
	while (!philosopher->restaurant->closed) //TODO check for deaths
	{
		eat(philosopher);
		powernap(philosopher);
		philosophize(philosopher);
	}
	return (NULL);
}

void	open_restaurant(t_restaurant *restaurant)
{
	int	i;

	i = 0;
	printf("Restaurant open at %zu\n", restaurant->opening_time);
	while (i < restaurant->num_philosophers)
	{
		printf("philosopher %d has entered the restaurant\n", i);
		if (pthread_create(&restaurant->philosophers[i].thread_id, NULL, &philosophical_routine,
					&restaurant->philosophers[i]) != 0)
			printf("thread creation error\n"); // TODO teardown
		i++;
	}
	i = 0;
	while (i < restaurant->num_philosophers)
	{
		if (pthread_join(restaurant->philosophers[i].thread_id, NULL) != 0)
			printf("thread creation error\n"); // TODO teardown
		i++;
	}
}
