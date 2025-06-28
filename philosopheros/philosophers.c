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
