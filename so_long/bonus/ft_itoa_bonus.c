/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:38:12 by hyseo             #+#    #+#             */
/*   Updated: 2021/11/15 19:40:45 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	itoa_count(long long n, int min)
{
	int	count;

	count = 0;
	if (n == 0 || min < 0)
		count = 1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*itoa_set(char *result, long long n, int i)
{
	if (n >= 10)
		itoa_set(result, n / 10, i - 1);
	result[i] = (n % 10) + '0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		count;
	int		min;

	min = 1;
	if (n < 0)
		min = -1;
	count = itoa_count((long long)n * min, min);
	result = malloc(sizeof(char) * (count + 1));
	if (min < 0 && (long long)n * min > 0)
	{
		result[0] = '-';
		itoa_set(result, ((long long)n * min), count - 1);
	}
	else if (min > 0 && (long long)n * min > 0)
		itoa_set(result, ((long long)n * min), count - 1);
	else
		result[0] = '0';
	result[count] = '\0';
	return (result);
}
