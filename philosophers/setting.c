/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:43:17 by hyseo             #+#    #+#             */
/*   Updated: 2022/01/18 17:43:55 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	long long		time;
	struct timeval	val;

	gettimeofday(&val, NULL);
	time = (long long)(val.tv_sec * 1000 + val.tv_usec / 1000) - cur_time;
	return (time);
}

bool	make_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num)
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
	info->num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->state = START;
	if (argc == 6)
	{
		info->must_eat = ft_atoi(argv[5]);
		if (info->must_eat == 0)
		{
			printf("\e[0;31m %dms all philosopher eat\n", 0);
			return (0);
		}
	}
	info->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->num);
	if (info->fork == NULL)
		return (0);
	pthread_mutex_init(&info->print, NULL);
	return (make_mutex(info));
}
