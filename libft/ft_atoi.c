/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 02:07:54 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/10 16:32:24 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
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
		if (*str == '-')
			min *= -1;
		str++;
	}
	if (min < 0)
		re = 0;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		if ((result += (*str - '0')) < 0)
			return (re);
		str++;
	}
	return (result * min);
}
