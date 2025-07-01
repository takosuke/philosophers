#import <stdio.h>
#import <stdlib.h>
#import <pthread.h>
#import <unistd.h>
#import <sys/time.h>

int meals = 0;
pthread_mutex_t l_fork;
pthread_mutex_t r_fork;

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
		usleep(500);
	return (0);
}

void *routine(void *str)
{
	for (int i = 0; i < 5; i++)
	{
		pthread_mutex_lock(&l_fork);
		pthread_mutex_lock(&r_fork);
		meals++;
		ft_usleep(200);
		printf("%s eaten %d meals\n", (char *)str, meals);
		pthread_mutex_unlock(&l_fork);
		pthread_mutex_unlock(&r_fork);
		printf("%s sleeping\n", (char *)str);
		ft_usleep(200);

	}
	return NULL;
}

int	main()
{
	pthread_t	t_id1;
	pthread_t	t_id2;

	pthread_mutex_init(&l_fork, NULL);
	pthread_mutex_init(&r_fork, NULL);
	pthread_create(&t_id1, NULL, &routine, "philo 1");
	pthread_create(&t_id2, NULL, &routine, "philo 2");
	pthread_join(t_id1, NULL);
	pthread_join(t_id2, NULL);
	pthread_mutex_destroy(&l_fork);
	pthread_mutex_destroy(&r_fork);
	return (0);
}
