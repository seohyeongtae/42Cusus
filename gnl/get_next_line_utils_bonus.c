/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:33:44 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/31 19:27:25 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char			*ft_strjoin(char const *s1, char const *s2)
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
	free((char *)s1);
	return (re);
}

char			*ft_strdup(const char *s1)
{
	char	*re;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	if (!(re = malloc(len + 1)))
		return (0);
	while (s1[i])
	{
		re[i] = s1[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}

char			*ft_strchr(const char *s, unsigned int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
