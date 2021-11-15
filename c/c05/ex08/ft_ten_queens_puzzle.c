/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 06:42:55 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/13 03:42:53 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_chess[10];
int		g_count;

int		ft_check(int start)
{
	int check;
	int i;

	check = 0;
	i = -1;
	while (++i < start)
	{
		check = g_chess[i] - g_chess[start];
		if (check < 0)
			check *= -1;
		if (g_chess[start] == g_chess[i] || check == start - i)
			return (0);
	}
	return (1);
}

void	ft_put_queens(int start)
{
	int		i;
	int		j;
	char	a;

	i = 0;
	j = 0;
	if (start == 10)
	{
		g_count++;
		while (j < 10)
		{
			a = g_chess[j] + '0';
			write(1, &a, 1);
			j++;
		}
		write(1, "\n", 1);
		return ;
	}
	while (i < 10)
	{
		g_chess[start] = i;
		if (ft_check(start))
			ft_put_queens(start + 1);
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int i;

	i = 0;
	g_count = 0;
	while (i < 10)
	{
		g_chess[i] = 0;
		i++;
	}
	ft_put_queens(0);
	return (g_count);
}
