/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:05:02 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/17 21:40:40 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		len;
	char	*re;

	len = ft_strlen(s) - 1;
	re = 0;
	if (!c)
		return ((char *)&s[len + 1]);
	while (len >= 0)
	{
		if (s[len] == (char)c)
		{
			re = (char *)&s[len];
			return (re);
		}
		len--;
	}
	return (re);
}
