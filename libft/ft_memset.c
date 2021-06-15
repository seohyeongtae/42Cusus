/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:21:17 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/07 13:24:08 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *dest, int c, unsigned int count)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		*(unsigned char *)(dest + i) = (unsigned char)c;
		i++;
	}
	return (dest);
}
