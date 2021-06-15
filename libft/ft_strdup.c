/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:03:16 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/17 21:34:01 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*re;
	int		i;
	int		len;

	i = 0;
	len = ft_len(s1);
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
