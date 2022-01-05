/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:57:32 by hyseo             #+#    #+#             */
/*   Updated: 2022/01/05 20:46:55 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<pthread.h>
#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef enum e_state
{
	START,
	THINKING,
	EATING,
	SLEEPING,
	DIED,
	FULL,
}		t_state;

typedef struct s_info
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	int all_eat;
	pthread_mutex_t	*fork;
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

bool	make_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		if (pthread_mutex_init(&info->fork[i], NULL) != 0)
		{
			printf("make mutex error  \n");
			return (0);
		}
		i++;
	}
	info->start_time = get_time(0);
	return (1);
}

bool	make_info(int argc, char **argv, t_info *info)
{
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->state = START;
	if (argc == 6)
	{
		info->must_eat = ft_atoi(argv[5]);
		if (info->must_eat == 0)
			return (0);
	}
	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->number_of_philosophers);
	if (info->fork == NULL)
		return (0);
	pthread_mutex_init(&info->print, NULL);
	return (make_mutex(info));
}

void	print_state(t_philo *philo, int state)
{
	usleep(100);
	if (pthread_mutex_lock(&philo->info->print) == 0)
	{
		if (philo->info->state == FULL || philo->info->state == DIED)
		{
			pthread_mutex_unlock(&philo->info->print);
			return;
		}
		else if (state == 1 && philo)
			printf("\e[0;32m %lld ms  %d  is sleeping\n", philo->cur_time, philo->i + 1);
		else if (state == 2 && philo)
			printf("\e[0;34m %lld ms  %d  is thinking\n", philo->cur_time, philo->i + 1);
		else if (state == 3 && philo)
			printf("\e[0;35m %lld ms  %d  is eating\n", philo->cur_time, philo->i + 1);
		else if (state == 4 && philo)
			printf("\e[0;33m %lld ms  %d  has taken a fork\n", philo->cur_time, philo->i + 1);
		if (philo->info->state != FULL && philo->info->state != DIED)
			pthread_mutex_unlock(&philo->info->print);
	}
}

void	do_sleep(t_philo *philo)
{
	if (philo->state == SLEEPING)
	{
		philo->cur_time = get_time(philo->info->start_time);
		print_state(philo, 1);
		while (get_time(philo->info->start_time) - philo->cur_time < philo->info->time_to_sleep)
			usleep(100);
		philo->state = THINKING;
		philo->cur_time = get_time(philo->info->start_time);
		print_state(philo, 2);
	}
}

void	do_eat(t_philo *philo)
{
	if (philo->state == EATING)
	{
		philo->cur_time = get_time(philo->info->start_time);
		philo->eat_time = philo->cur_time;
		print_state(philo, 3);
		philo->cnt_eat += 1;
		if (philo->cnt_eat == philo->info->must_eat
		&& philo->info->must_eat != 0)
			philo->info->all_eat += 1;
		while (get_time(philo->info->start_time) - philo->cur_time < philo->info->time_to_eat)
			usleep(100);
		philo->state = SLEEPING;
		pthread_mutex_unlock(&philo->info->fork[philo->left]);
		pthread_mutex_unlock(&philo->info->fork[philo->right]);
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
			print_state(philo, 4);
		}
	}
	if (philo->state == THINKING && cnt == 1)
	{
		if (pthread_mutex_lock(&philo->info->fork[philo->right]) == 0 &&
		pthread_mutex_lock(&philo->info->fork[philo->left]) == 0)
		{
			philo->state = EATING;
			philo->cur_time = get_time(philo->info->start_time);
			print_state(philo, 4);
		}
	}
}

void	*run_thread(void *philo)
{
	t_philo *p;
	
	p = philo;
	while(p->info->state != FULL && p->info->state != DIED)
	{
		pick_fork(philo);
		do_eat(philo);
		do_sleep(philo);
		usleep(200);
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
		if (p->info->state == FULL || p->info->state == DIED)
			break;
		if (p->info->all_eat == p->info->number_of_philosophers)
		{
			p->info->state = FULL;
			if (pthread_mutex_lock(&p->info->print) == 0)
				printf("\e[0;31m %lld ms  all philosopher eat\n", time);
			break;
		}
		if (time - p->eat_time > p->info->time_to_die)
		{
			p->info->state = DIED;
			if (pthread_mutex_lock(&p->info->print) == 0)
				printf("\e[0;31m %lld ms  %d  is died\n", time, p->i + 1);
			break;
		}
	}
	return (NULL);
}

bool	make_philo(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		philo[i].i = i;
		philo[i].right = (i + 1) % info->number_of_philosophers;
		philo[i].left = i;
		philo[i].cur_time = info->start_time;
		philo[i].eat_time = info->start_time;
		philo[i].info = info;
		philo[i].state = THINKING;
		if (pthread_create(&philo[i].run_thread, NULL, run_thread, &philo[i]) ||
		pthread_create(&philo[i].check_thread, NULL, check_thread, &philo[i]))
			return (0);
		if (pthread_detach(philo[i].run_thread) ||
		pthread_detach(philo[i].check_thread))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	if (argc == 5 || argc == 6)
	{
		if (!make_info(argc, argv, &info))
			return (1);
	}
	else
	{
		printf("argv error!");
		return (1);
	}
	philo = (t_philo *)malloc(info.number_of_philosophers * sizeof(t_philo));
	if (philo == NULL)
		return (1);
	if (!make_philo(&info, philo))
	{
		free(philo);
		printf("thread error!");
		return (1);
	}
	while(info.state != DIED && info.state != FULL);
	// system("leaks a.out");
	usleep(100*1000);
	//free(philo);
	//printf("ebdebd \n");
	return (0);
}
