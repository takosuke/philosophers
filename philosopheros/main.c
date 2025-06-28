#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_restaurant restaurant;

	if (argc < 5 || argc > 6)
	{
		printf("wrong usage\n");
		return (1);
	}
	restaurant = init_restaurant(argc, argv);
	init_forks(&restaurant);
	init_philosophers(&restaurant);
	for (int i = 0; i < restaurant.num_philosophers; i++)
	{
		printf("philosopher %d l_fork: %p r_fork: %p\n", restaurant.philosophers[i].id, restaurant.philosophers[i].l_fork, restaurant.philosophers[i].r_fork);
	}
	return (0);
}
