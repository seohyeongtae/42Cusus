/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 13:52:43 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/20 18:13:39 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int destsize)
{
	unsigned int i;

	i = 0;
	while (src[i] && i + 1 < destsize)
	{
		dest[i] = src[i];
		i++;
	}
	if (destsize > 0)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
