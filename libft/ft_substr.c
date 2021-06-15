/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:08:17 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/20 18:41:11 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char	*re;

	if (s == 0)
		return (0);
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	if (!(re = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (ft_strlen(s) <= start)
	{
		re[0] = 0;
		return (re);
	}
	ft_strlcpy(re, s + start, len + 1);
	return (re);
}
