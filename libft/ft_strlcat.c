/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 06:10:44 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/04 12:58:29 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*dest && i < size)
	{
		i++;
		dest++;
	}
	while (*src && i + 1 < size)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	if (i < size)
		*dest = '\0';
	while (*src)
	{
		i++;
		src++;
	}
	return (i);
}
