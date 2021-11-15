/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:22:47 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/12 13:43:10 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*g_base;
char	*g_str;
int		g_len;
int		g_min;
int		g_num;

void	ft_change(int count, int end)
{
	int		start;
	long	result;
	long	square;
	int		len;
	int		i;

	start = end - count;
	len = count;
	square = 1;
	result = 0;
	while (len-- >= 0)
		square *= g_len;
	while (count-- >= 0)
	{
		square /= g_len;
		i = 0;
		while (g_base[i++])
		{
			if (g_base[i] == g_str[start])
				result += i * square;
		}
		start++;
	}
	g_num = result * g_min;
}

int		ft_find_final_check(char a)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (g_base[i])
	{
		if (g_base[i] == a)
			check++;
		i++;
	}
	if (check == 0)
		return (0);
	else
		return (1);
}

void	ft_find_check(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_find_final_check(str[i]))
		{
			if (!ft_find_final_check(str[i + 1]))
			{
				count++;
				ft_change(count, i);
				return ;
			}
			count++;
		}
		i++;
	}
}

int		ft_check_base(char *base, char *str)
{
	int i;
	int j;
	int count;

	g_str = str;
	i = 0;
	count = 0;
	while (base[i])
	{
		j = 0;
		while (g_base[j])
		{
			if (g_base[j] == base[i])
			{
				count++;
				if (count > g_len)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;

	i = 0;
	g_base = base;
	g_min = 1;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
				|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		i++;
	}
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			g_min *= -1;
		str++;
	}
	g_len = i;
	if (i <= 1 || (!ft_check_base(base, str)))
		return (0);
	ft_find_check(str);
	return (g_num);
}
