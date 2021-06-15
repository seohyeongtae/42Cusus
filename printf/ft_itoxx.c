/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:21:17 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/10 14:56:37 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*itoxx_set(char *re, long long n, char *base, int count)
{
	if (n >= 16)
	{
		re[count] = base[n % 16];
		itoxx_set(re, n / 16, "0123456789ABCDEF", count + 1);
		return (0);
	}
	re[count] = base[n % 16];
	re[count + 1] = '\0';
	return (re);
}

char	*ft_itoxx(unsigned int n)
{
	char			re[100];
	int				count;
	unsigned int	i;
	char			*result;

	i = 0;
	itoxx_set(re, n, "0123456789ABCDEF", 0);
	count = ft_strlen(re);
	if (!(result = (char *)malloc(sizeof(char) * count)))
		return (0);
	while (i < ft_strlen(re))
	{
		result[i] = re[count - 1];
		count--;
		i++;
	}
	result[i] = '\0';
	return (result);
}
