/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 13:28:28 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/19 18:00:41 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *nee, unsigned int len)
{
	unsigned int	i;
	unsigned int	result;
	unsigned int	j;

	if (!(*nee))
		return ((char *)stack);
	i = 0;
	while (stack[i] && i < len)
	{
		j = 0;
		while (stack[i] && stack[i] != nee[j])
			i++;
		result = i;
		while (stack[i] && stack[i] == nee[j] && i < len)
		{
			j++;
			i++;
		}
		if (!nee[j])
			return ((char *)&stack[result]);
		if (stack[result])
			i = result + 1;
	}
	return (0);
}
