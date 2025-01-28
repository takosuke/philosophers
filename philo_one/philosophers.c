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

void	init_philosophers(t_restaurant *restaurant)
{
	long	i;

	restaurant->philosophers = (t_philo *)malloc(restaurant->num_philosophers * sizeof(t_philo));

	i = 0;
	while (i < restaurant->num_philosophers)
	{
		restaurant->philosophers[i].id = i + 1;
		restaurant->philosophers[i].l_fork = &(restaurant->forks[i]);
		if (i != restaurant->num_philosophers - 1)
			restaurant->philosophers[i].r_fork = &(restaurant->forks[i + 1]);
		else
			restaurant->philosophers[i].r_fork = &(restaurant->forks[0]);
		printf("%ld\n", i);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_restaurant	*restaurant;
//	if (argc == 6)
//	set a max_meals option or something
	if (argc > 4)
	{
		restaurant = init_restaurant(argv);
		printf("Restaurant num_philosophers: %ld\n", restaurant->num_philosophers);
		init_forks(restaurant);
		init_philosophers(restaurant);
		int i = 0;
		while (i < restaurant->num_philosophers)
		{
			printf("Philosopher id: %d\n", restaurant->philosophers[i].id);
			printf("Left fork id: %d \t Right fork id: %d\n", restaurant->philosophers[i].l_fork->id, restaurant->philosophers[i].r_fork->id);
			i++;
		}
	}
	return (0);
}
