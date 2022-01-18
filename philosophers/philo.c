/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:57:32 by hyseo             #+#    #+#             */
/*   Updated: 2022/01/18 17:45:02 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*run_thread(void *philo)
{
	t_philo	*p;

	p = philo;
	while (p->info->state != FULL && p->info->state != DIED)
	{
		pick_fork(philo);
		do_eat(philo);
		do_sleep(philo);
		usleep(10);
	}
	return (NULL);
}

void	*c_thread(void *philo)
{
	t_philo		*p;
	long long	time;

	p = philo;
	while (1)
	{
		time = get_time(p->info->start_time);
		if (p->info->state == FULL || p->info->state == DIED)
			break ;
		if (p->info->all_eat == p->info->num)
		{
			if (pthread_mutex_lock(&p->info->print) == 0)
				printf("\e[0;31m %lldms all philosopher eat\n", time);
			p->info->state = FULL;
			break ;
		}
		if (time - p->cur_time > p->info->time_to_die)
		{
			if (pthread_mutex_lock(&p->info->print) == 0)
				printf("\e[0;31m %lldms %d is died\n", time, p->i + 1);
			p->info->state = DIED;
			break ;
		}
	}
	return (NULL);
}

bool	make_philo(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->num)
	{
		philo[i].i = i;
		philo[i].right = (i + 1) % info->num;
		philo[i].left = i;
		philo[i].cur_time = info->start_time;
		philo[i].eat_time = info->start_time;
		philo[i].info = info;
		philo[i].state = THINKING;
		if (pthread_create(&philo[i].run_thread, NULL, run_thread, &philo[i])
			|| pthread_detach(philo[i].run_thread))
			return (0);
		if (pthread_create(&philo[i].check_thread, NULL, c_thread, &philo[i])
			|| pthread_detach(philo[i].check_thread))
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
		return (1);
	philo = (t_philo *)malloc(info.num * sizeof(t_philo));
	if (philo == NULL)
		return (1);
	if (!make_philo(&info, philo))
	{
		free(philo);
		printf("thread error!");
		return (1);
	}
	while (info.state != DIED && info.state != FULL)
		usleep(10);
	usleep (1000 * 1000);
	free (philo);
	return (0);
}
