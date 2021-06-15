/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:21:14 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/04 17:09:59 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int count, unsigned int size)
{
	unsigned char	*result;
	unsigned int	i;

	i = 0;
	if (!(result = malloc(count * size)))
		return (0);
	while (i < count * size)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}
