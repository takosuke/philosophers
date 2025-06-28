#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int		res;
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

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		ft_usleep(500);
	return (0);
}
