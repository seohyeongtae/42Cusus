/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 06:38:29 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/13 08:18:43 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *result;
	int i;

	if (min >= max)
		return (0);
	i = 0;
	result = (int *)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		result[i] = min;
		i++;
		min++;
	}
	return (result);
}
