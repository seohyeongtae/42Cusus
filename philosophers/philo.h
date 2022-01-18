/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:01:16 by hyseo             #+#    #+#             */
/*   Updated: 2022/01/18 17:42:54 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<unistd.h>
# include<pthread.h>
# include<sys/time.h>
# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

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
	int				num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				all_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	t_state			state;
	long long		start_time;
}		t_info;

typedef struct s_philo
{
	int			i;
	int			right;
	int			left;
	int			cnt_eat;
	long long	cur_time;
	long long	eat_time;
	t_info		*info;
	pthread_t	run_thread;
	pthread_t	check_thread;
	t_state		state;
}		t_philo;

int			ft_atoi(const char *str);
long long	get_time(long cur_time);
bool		make_mutex(t_info *info);
bool		make_info(int argc, char **argv, t_info *info);

void		print_state(t_philo *philo, int state);
void		do_sleep(t_philo *philo);
void		do_eat(t_philo *philo);
void		pick_fork(t_philo *philo);

void		*run_thread(void *philo);
void		*c_thread(void *philo);
bool		make_philo(t_info *info, t_philo *philo);

#endif