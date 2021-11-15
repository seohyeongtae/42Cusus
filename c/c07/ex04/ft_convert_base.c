/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 02:06:17 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/14 16:46:13 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		g_num;
char	*g_base_f;
char	*g_base_t;
int		g_min;
int		g_result;

int		ft_strlen(char *str);
int		ft_check_base_overlap(char *src, int lne);
int		ft_check_base(char *src);

void	ft_putchar(char *nbr, int count, int base_from_len)
{
	int a;
	int i;
	int j;

	a = count;
	while (a > 0)
	{
		nbr--;
		a--;
	}
	i = 0;
	while (nbr[i] && i <= count)
	{
		j = 0;
		while (g_base_f[j])
		{
			if (g_base_f[j] == nbr[i])
			{
				g_num *= base_from_len;
				g_num += j;
			}
			j++;
		}
		i++;
	}
}

int		ft_nbr_final_check(char a)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (g_base_f[i])
	{
		if (g_base_f[i] == a)
			check++;
		i++;
	}
	if (check == 0)
		return (0);
	else
		return (1);
}

void	ft_nbr_check(char *nbr, int base_from_len)
{
	int i;

	while ((*nbr >= 9 && *nbr <= 13) || *nbr == ' ')
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			g_min = g_min * -1;
		nbr++;
	}
	i = 0;
	while (*nbr)
	{
		if (ft_nbr_final_check(*nbr))
		{
			if (!ft_nbr_final_check(*(nbr + 1)))
			{
				ft_putchar(nbr, i, base_from_len);
				return ;
			}
		}
		i++;
		nbr++;
	}
}

char	*ft_convert(int num, int base_to_len)
{
	char	*a;
	int		i;
	int		c;

	i = 0;
	c = num;
	while (num > 0)
	{
		num = num / base_to_len;
		i++;
	}
	if (g_min < 0)
		i = i + 1;
	g_num = i;
	a = (char *)malloc(i);
	a[i] = '\0';
	while (c > 0)
	{
		a[i - 1] = g_base_t[c % base_to_len];
		c = c / base_to_len;
		i--;
	}
	if (g_min < 0)
		a[0] = '-';
	return (a);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		re_len;
	char	*result;
	int		base_from_len;
	int		base_to_len;

	re_len = 0;
	g_num = 0;
	g_base_f = base_from;
	g_base_t = base_to;
	g_min = 1;
	g_result = 0;
	if (ft_check_base(base_from) || (ft_check_base(base_to)))
		return (0);
	base_from_len = ft_strlen(base_from);
	base_to_len = ft_strlen(base_to);
	ft_nbr_check(nbr, base_from_len);
	result = (char *)malloc(g_num);
	result = ft_convert(g_num, base_to_len);
	return (result);
}
