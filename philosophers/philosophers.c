#include "philosophers.h"

long	ft_atol(const char *str)
{
	long		res;
	char	sign;

	res = 0;
	sign = '+';
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		sign = *str++;
	while ((*str >= '0' && *str <= '9'))
		res = (res * 10) + (*str++ - '0');
	if (sign == '-')
		res *= -1;
	return (res);
}

t_restaurant *init_restaurant(int argc, char **argv)
{
	t_restaurant	*restaurant;
	restaurant = malloc(sizeof(t_restaurant));
	if (restaurant == NULL)
		return (NULL);
	// TODO verify all params are within the req ranges
	restaurant->num_philosophers = ft_atol(argv[1]);
	restaurant->time_to_die = ft_atol(argv[2]);
	restaurant->time_to_eat = ft_atol(argv[3]);
	restaurant->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		restaurant->max_meals = ft_atol(argv[5]);
	else
		restaurant->max_meals = -1;
	restaurant->philosopher = malloc(sizeof(t_philosopher) * restaurant->num_philosophers);
	return (restaurant);
}

int	main(int argc, char **argv)
{
	t_restaurant *restaurant;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philosophers {number_of_philosophers} {time_to_eat} {time_to_sleep} (optional){number_of_times_each_philosopher_must_ear}\n");
		return (1);
	}
	restaurant = init_restaurant(argc, argv);
	if (restaurant == NULL)
		return (1);
	free(restaurant);
	return (0);
}
