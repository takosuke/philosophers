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
	printf("opening restaurant\n");
	init_forks(&restaurant);
	init_philosophers(&restaurant);
	printf("everyone at the table\n");
	for (int i = 0; i < restaurant.num_philosophers; i++)
	{
		printf("philosopher %d l_fork: %p r_fork: %p restaurant: %p\n", restaurant.philosophers[i].id, restaurant.philosophers[i].l_fork, restaurant.philosophers[i].r_fork, restaurant.philosophers[i].restaurant);
	}
	open_restaurant(&restaurant);
	return (0);
}
