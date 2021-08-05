/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:20:10 by hyseo             #+#    #+#             */
/*   Updated: 2021/07/29 16:23:09 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*re;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	re = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!re)
		print_error();
	while (s1[i])
	{
		re[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		re[i] = s2[j];
		i++;
		j++;
	}
	re[i] = 0;
	free((char *)s1);
	return (re);
}
