/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:57:32 by hyseo             #+#    #+#             */
/*   Updated: 2021/12/16 20:46:24 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<pthread.h>
#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>


typedef enum e_state
{
	START,
	THINKING,
	EATING,
	SLEEPING,
	DIED,
	FULL,
}		t_state;


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
	t_state	state;
	long long start_time;
}		t_info;

typedef struct s_philo
{
	int	i;
	int	right;
	int left;
	int cnt_eat;
	long long	cur_time;
	long long	eat_time;
	t_info	*info;
	pthread_t run_thread;
	pthread_t check_thread;
	t_state	state;
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
	time = (long long)(val.tv_sec * 1000 + val.tv_usec / 1000) - cur_time;
	//printf("%lld  \n", time);
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
	info->state = START;
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
	//pthread_mutex_init(&info->eat, NULL);
	pthread_mutex_init(&info->print, NULL);
	return;
}

void	do_sleep(t_philo *philo)
{
	if (philo->state == SLEEPING)
	{
		if (pthread_mutex_lock(&philo->info->print) == 0)
		{
			pthread_mutex_unlock(&philo->info->print);
			philo->cur_time = get_time(philo->info->start_time);
			printf("\e[0;32m %lld  %d  is SLEEPING\n", philo->cur_time, philo->i + 1);
		}
		usleep(philo->info->time_to_sleep * 1000);
		philo->state = THINKING;
		if (pthread_mutex_lock(&philo->info->print) == 0)
		{
			pthread_mutex_unlock(&philo->info->print);
			philo->cur_time = get_time(philo->info->start_time);
			printf("\e[0;34m %lld  %d  is THINKING\n", philo->cur_time, philo->i + 1);
		}
		//usleep(50);
	}
}

void	do_eat(t_philo *philo)
{
	if (philo->state == EATING)
	{
		if (pthread_mutex_lock(&philo->info->print) == 0)
		{
			pthread_mutex_unlock(&philo->info->print);
			philo->cur_time = get_time(philo->info->start_time);
			philo->eat_time = philo->cur_time;
			printf("\e[0;35m %lld  %d  is EATING\n", philo->cur_time, philo->i + 1);
		}
		usleep(philo->info->time_to_eat * 1000);
		philo->state = SLEEPING;
		pthread_mutex_unlock(&philo->info->fork[philo->left]);
		pthread_mutex_unlock(&philo->info->fork[philo->right]);
		philo->info->all_eat += 1;
		// do_sleep(philo);
		// printf("%d  pppp\n\n", philo->info->all_eat);
	}
}

void	pick_fork(t_philo *philo)
{
	int cnt;

	cnt = 0;
	cnt = philo->i % 2;
	if (philo->state == THINKING && cnt == 0)
	{
		if (pthread_mutex_lock(&philo->info->fork[philo->left]) == 0 &&
		pthread_mutex_lock(&philo->info->fork[philo->right]) == 0)
		{
			philo->state = EATING;
			philo->cur_time = get_time(philo->info->start_time);
		if (pthread_mutex_lock(&philo->info->print) == 0)
		{
			pthread_mutex_unlock(&philo->info->print);
			printf("\e[0;33m%lld  %d  has a fork\n", philo->cur_time, philo->i + 1);
		}
			// do_eat(philo);
		}
	}
	if (philo->state == THINKING && cnt == 1)
	{
		if (pthread_mutex_lock(&philo->info->fork[philo->right]) == 0 &&
		pthread_mutex_lock(&philo->info->fork[philo->left]) == 0)
		{
			philo->state = EATING;
			philo->cur_time = get_time(philo->info->start_time);
			if (pthread_mutex_lock(&philo->info->print) == 0)
			{
				pthread_mutex_unlock(&philo->info->print);
				printf("\e[0;33m%lld  %d  has a fork\n", philo->cur_time, philo->i + 1);
			}
			// do_eat(philo);
		}
	}
}

void	*run_thread(void *philo)
{
	t_philo *p;
	
	p = philo;
	while(1)
	{
		// if (p->info->state == FULL || p->info->state == DIED)
		// 	break;
		pick_fork(philo);
		do_eat(philo);
		do_sleep(philo);
	}
	return (NULL);
}

void	*check_thread(void *philo)
{
	t_philo *p;
	
	p = philo;
	long long	time;
	while (1)
	{
		time = get_time(p->info->start_time);
		
		//philo->cur_time = get_time(philo->info->start_time);
		if (p->info->state == FULL || p->info->state == DIED)
			break;
		if (time - p->eat_time > p->info->time_to_die)
		{
			p->state = DIED;
			p->info->state = DIED;
			if (pthread_mutex_lock(&p->info->print) == 0)
			{
				printf("\e[0;31m%lld  %d  is DIEDDDDDDDDDDDDDDDDDDDDDD\n", time, p->i + 1);
				//printf("%d   sfasdfdasf time 11\n", p->info->time_to_die);
				// printf("%lld   time time 22\n", time);
				// printf("%lld   eat time 22\n", p->eat_time);
				// printf("%lld   time-eattime 33\n", time - p->eat_time);
				// printf("%lld   died time\n", get_time(p->info->start_time) - time);
			}
			break;
		}
		
	}
	return (NULL);
}

void	make_philo(t_info *info, t_philo *philo)
{
	int	i;
	void **a;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		//printf("aaaaa + %d \n", i);
		philo[i].i = i;
		philo[i].right = (i + 1) % info->number_of_philosophers;
		philo[i].left = i;
		philo[i].cur_time = info->start_time;
		philo[i].eat_time = info->start_time;
		philo[i].info = info;
		philo[i].state = THINKING;
		if (pthread_create(&philo[i].run_thread, NULL, run_thread, &philo[i]) ||
		pthread_detach(philo[i].run_thread))
			printf("whyyyyy \n");
		if (pthread_create(&philo[i].check_thread, NULL, check_thread, &philo[i]) ||
		pthread_detach(philo[i].check_thread))
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
	// died 가 생길때까지 or cnt가 다 채워질 때까지
	while(info.state != DIED && info.state != FULL);
	// 전부다 free 시키고 종료하기
	printf("%lld  sdfjadkfjladsfjlksdjfl \n", get_time(info.start_time));
	//system("leaks a.out");
	return (0);
}
