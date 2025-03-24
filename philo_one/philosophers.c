#include "philosophers.h"

t_restaurant	*init_restaurant(char **argv)
{
	t_restaurant	*restaurant;
	restaurant = (t_restaurant *)malloc(sizeof(t_restaurant));
	if (restaurant == NULL)
		return (NULL);
	restaurant->num_philosophers = atoi(argv[1]);
	restaurant->time_to_die = atoi(argv[2]);
	restaurant->time_to_eat = atoi(argv[3]);
	restaurant->time_to_sleep = atoi(argv[4]);
	return (restaurant);
}

void	init_forks(t_restaurant *restaurant)
{
	long	i;
	restaurant->forks = (t_fork *)malloc(restaurant->num_philosophers * sizeof(t_fork));

	i = 0;
	while (i < restaurant->num_philosophers)
	{
		restaurant->forks[i].id = i;
		printf("%ld\n", i);
		i++;
	}
}

void	init_philosophers(t_restaurant *restaurant, long times_to_eat)
{
	long	i;

	restaurant->philosophers = (t_philo *)malloc(restaurant->num_philosophers * sizeof(t_philo));

	i = 0;
	while (i < restaurant->num_philosophers)
	{
		restaurant->philosophers[i].id = i + 1;
		restaurant->philosophers[i].times_to_eat = times_to_eat;
		restaurant->philosophers[i].l_fork = &(restaurant->forks[i]);
		if (i != restaurant->num_philosophers - 1)
			restaurant->philosophers[i].r_fork = &(restaurant->forks[i + 1]);
		else
			restaurant->philosophers[i].r_fork = &(restaurant->forks[0]);
		printf("%ld\n", i);
		i++;
	}
}

void	*eat()
{
}

int		main(int argc, char **argv)
{
	t_restaurant	*restaurant;
//	if (argc == 6)
//
//	set a max_meals option or something
	if (argc > 4 && argc < 7)
	{
		// check for arg errors
		restaurant = init_restaurant(argv);
		init_forks(restaurant);
		if (argc == 6)
			init_philosophers(restaurant, argv[5]);
		else
			init_philosophers(restaurant, -1);
		int i = 0;
		// start sim
		// clean
	}
	/*
	else
		error
		*/
	return (0);
}
