/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:41:20 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/19 17:51:53 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		check_str(char *s1, char *set)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (s1[i] && set[j])
	{
		if (s1[i] && s1[i] == set[j])
		{
			count++;
			j = -1;
			i++;
		}
		j++;
	}
	return (count);
}

int		check_strr(char *s1, char *set)
{
	int i;
	int j;
	int count;

	i = ft_strlen(s1) - 1;
	j = 0;
	count = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			count++;
			j = -1;
			i--;
		}
		j++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*re;
	int		count;
	int		count_r;
	int		i;
	int		j;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	count = check_str((char *)s1, (char *)set);
	if ((int)ft_strlen(s1) <= count)
		return (ft_strdup(""));
	count_r = check_strr((char *)s1, (char *)set);
	i = count;
	j = 0;
	if (!(re = malloc(ft_strlen(s1) - count - count_r + 1)))
		return (0);
	ft_strlcpy(re, s1 + i, (int)ft_strlen(s1) - count_r - count + 1);
	return (re);
}
