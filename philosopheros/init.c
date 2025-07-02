#include "philosophers.h"

void	init_philosophers(t_restaurant *restaurant)
{
	int	i;
	t_philosopher	*philo;

	i = 0;
	while (i < restaurant->num_philosophers)
	{
		philo = &restaurant->philosophers[i];
		philo->restaurant = restaurant;
		philo->id = i;
		philo->times_eaten = 0;
		philo->last_meal_time = restaurant->opening_time;;
		if (i == 0)
			philo->l_fork = &restaurant->forks[restaurant->num_philosophers - 1];
		else
			philo->l_fork = &restaurant->forks[i - 1];
		philo->r_fork = &restaurant->forks[i];
		i++;
	}
}

void	init_forks(t_restaurant *restaurant)
{
	int	i;

	i = 0;
	while (i < restaurant->num_philosophers)
	{
		pthread_mutex_init(&restaurant->forks[i], NULL);
		i++;
	}
}

t_restaurant init_restaurant(int argc, char **argv)
{
	t_restaurant	restaurant;
	restaurant.num_philosophers = ft_atoi(argv[1]);
	restaurant.time_to_die = ft_atoi(argv[2]);
	restaurant.time_to_eat = ft_atoi(argv[3]);
	restaurant.time_to_sleep = ft_atoi(argv[4]);
	restaurant.closed = 0;
	restaurant.opening_time = get_current_time();
	if (argc == 6)
		restaurant.max_meals = ft_atoi(argv[5]);
	else
		restaurant.max_meals = -1;
	restaurant.philosophers = malloc(sizeof(t_philosopher) * restaurant.num_philosophers);
//	if (restaurant.philosophers == NULL)
//		return (NULL);
	restaurant.forks = malloc(sizeof(pthread_mutex_t) * restaurant.num_philosophers);
//	if (restaurant.forks == NULL)
//		return (NULL);
	return (restaurant);
}
