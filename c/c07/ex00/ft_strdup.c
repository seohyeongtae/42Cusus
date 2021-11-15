/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 06:06:40 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/13 08:19:27 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*re;
	int		i;

	i = 0;
	while (src[i])
		i++;
	re = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		re[i] = src[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}
