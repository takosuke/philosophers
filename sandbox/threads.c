#import <stdio.h>
#import <stdlib.h>
#import <pthread.h>
#import <unistd.h>
#import <sys/time.h>

int meals = 0;
pthread_mutex_t lock;

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

void	eating(char *str)
{
	pthread_mutex_lock(&lock);
	meals++;
	usleep(500);
	printf("eating %s\n", str);
	pthread_mutex_unlock(&lock);
}

void	sleeping(char *str)
{
	usleep(500);
	printf("sleeping %s\n", str);
}

void	thinking(char *str)
{
	usleep(500);
	printf("thinking %s\n", str);
}

void	routine(char *arg)
{
	printf("%s\n", arg);
	eating(arg);
	sleeping(arg);
	thinking(arg);
	printf("done\n");
}

int	main()
{
	pthread_t t_id;
	pthread_t t_id2;

	pthread_mutex_init(&lock, NULL);
	for (int i = 0; i < 5; i++)
	{
		printf("creating thread %d\n", i);
		pthread_create(&t_id, NULL, &routine, "Pooop");
		pthread_create(&t_id2, NULL, &routine, "Peeep");
		printf("created thread\n");
		printf("joining thread\n");
		pthread_join(t_id, NULL);
		pthread_join(t_id2, NULL);
		printf("joined thread %d eaten %d times\n", i, meals);
	}
	pthread_mutex_destroy(&lock);

	return 0;
}
