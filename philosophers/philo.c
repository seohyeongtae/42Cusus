/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:57:32 by hyseo             #+#    #+#             */
/*   Updated: 2021/12/14 19:24:03 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<pthread.h>
#include<sys/time.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct s_philo
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
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

void	make_philo(int argc, char **argv, t_philo *philo)
{
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	return;
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc == 5 || argc == 6)
		make_philo(argc, argv, &philo);
	else
	{
		printf("argc error!");
		return (0);
	}
	return (0);
}
