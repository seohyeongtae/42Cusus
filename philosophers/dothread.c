/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dothread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:44:31 by hyseo             #+#    #+#             */
/*   Updated: 2022/01/18 17:45:01 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *p, int state)
{
	if (pthread_mutex_lock(&p->info->print) == 0)
	{
		if (p->info->state == FULL || p->info->state == DIED)
		{
			pthread_mutex_unlock(&p->info->print);
			return ;
		}
		else if (state == 1 && p)
			printf("\e[0;32m%lldms %d is sleeping\n", p->cur_time, p->i + 1);
		else if (state == 2 && p)
			printf("\e[0;34m%lldms %d is thinking\n", p->cur_time, p->i + 1);
		else if (state == 3 && p)
			printf("\e[0;35m%lldms %d is eating\n", p->cur_time, p->i + 1);
		else if (state == 4 && p)
			printf("\e[0;33m%lldms %d has taken a fork\n", p->cur_time, p->i + 1);
		if (p->info->state != FULL && p->info->state != DIED)
			pthread_mutex_unlock(&p->info->print);
	}
}

void	do_sleep(t_philo *p)
{
	if (p->state == SLEEPING)
	{
		p->cur_time = get_time(p->info->start_time);
		print_state(p, 1);
		while (get_time(p->info->start_time) - p->cur_time
			< p->info->time_to_sleep)
			usleep(100);
		p->state = THINKING;
		p->cur_time = get_time(p->info->start_time);
		print_state(p, 2);
	}
}

void	do_eat(t_philo *p)
{
	if (p->state == EATING)
	{
		p->cur_time = get_time(p->info->start_time);
		p->eat_time = p->cur_time;
		print_state(p, 3);
		p->cnt_eat += 1;
		if (p->cnt_eat == p->info->must_eat
			&& p->info->must_eat != 0)
			p->info->all_eat += 1;
		while (get_time(p->info->start_time) - p->cur_time
			< p->info->time_to_eat)
			usleep(100);
		p->state = SLEEPING;
		pthread_mutex_unlock(&p->info->fork[p->left]);
		pthread_mutex_unlock(&p->info->fork[p->right]);
	}
}

void	pick_fork(t_philo *philo)
{
	int	cnt;

	cnt = 0;
	cnt = philo->i % 2;
	if (cnt == 0 && philo->state == THINKING)
	{
		philo->cur_time = get_time(philo->info->start_time);
		if (pthread_mutex_lock(&philo->info->fork[philo->left]) == 0
			&& pthread_mutex_lock(&philo->info->fork[philo->right]) == 0)
		{
			philo->state = EATING;
			print_state(philo, 4);
		}
	}
	if (cnt == 1 && philo->state == THINKING)
	{
		philo->cur_time = get_time(philo->info->start_time);
		if (pthread_mutex_lock(&philo->info->fork[philo->right]) == 0
			&& pthread_mutex_lock(&philo->info->fork[philo->left]) == 0)
		{
			philo->state = EATING;
			print_state(philo, 4);
		}
	}
}
