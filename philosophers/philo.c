/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:57:32 by hyseo             #+#    #+#             */
/*   Updated: 2021/12/15 19:57:59 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<pthread.h>
#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>

// eat, print mutex 가 필요한 이유는 context switch 가 일어나면서
// eat 혹은 print가 실행되지 않을 수 있다 -> 경쟁상태, 무한 점유 가 일어날 수 있다.
// 포크 2개는 쥐었지만 eat 혹은 print가 실행되지 않아 자원을 반환하지 않을 수 있다.
typedef struct s_info
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int all_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	print;
	long long start_time;
}		t_info;

typedef struct s_philo
{
	int	i;
	int	right;
	int left;
	int cnt_eat;
	long long cur_time;
	t_info	*info;
	pthread_t run_thread;
	pthread_t check_thread;
}		t_philo;


int	ft_atoi(const char *str)
{
	long long		result;
	int				min;
	int				re;

	result = 0;
	min = 1;
	re = -1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		printf("argv error!");
		exit(0);
	}
	if (min < 0)
		re = 0;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += (*str - '0');
		if (result < 0)
			return (re);
		str++;
	}
	return (result * min);
}

long long	get_time(long cur_time)
{
	long long	time;
	struct timeval val;

	gettimeofday(&val, NULL);
	time = (long long)(val.tv_sec + val.tv_usec) - cur_time;
	return time;
}

void	make_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		if (pthread_mutex_init(&info->fork[i], NULL) != 0)
		{
			printf("hterejl  \n");
			exit(1);
		}
		i++;
	}
	info->start_time = get_time(0);
}

void	make_info(int argc, char **argv, t_info *info)
{
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		if (info->number_of_times_each_philosopher_must_eat == 0)
			exit(1);
	}
	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->number_of_philosophers);
	if (info->fork == NULL)
		exit(1);
	make_mutex(info);
	pthread_mutex_init(&info->eat, NULL);
	pthread_mutex_init(&info->print, NULL);
	return;
}

void	*run_thread(void *t_philo)
{
	printf("run_thread   \n");
	printf("\n");
	return (NULL);
}

void	*check_thread(void *t_philo)
{
	printf("hrerer \n");
	printf("\n");
	int a = 0;
	while (a < 1000000)
	{
		//printf("hrerer \n");
		a++;
	}
	
	return (NULL);
}

void	make_philo(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		printf("aaaaa + %d \n", i);
		philo[i].i = i;
		philo[i].right = (i + 1) % info->number_of_philosophers;
		philo[i].left = i;
		philo[i].cur_time = info->start_time;
		philo[i].info = info;
		if (pthread_create(&philo[i].check_thread, NULL, check_thread, &philo[i]) ||
		pthread_detach(philo[i].check_thread))
			printf("whyyyyy \n");
		if (pthread_create(&philo[i].run_thread, NULL, run_thread, &philo[i]) ||
		pthread_detach(philo[i].run_thread))
			printf("whyyyyy \n");

		i++;
	}
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	if (argc == 5 || argc == 6)
		make_info(argc, argv, &info);
	else
		exit(1);
	philo = (t_philo *)malloc(info.number_of_philosophers * sizeof(t_philo));
	if (philo == NULL)
		exit(1);
	make_philo(&info, philo);
	return (0);
}
