/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 20:54:02 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/24 22:16:39 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(const char *str)
{
	unsigned int count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char	*re;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s1) && !(s2))
		return (0);
	if (!(re = (char *)malloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
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
	return (re);
}
