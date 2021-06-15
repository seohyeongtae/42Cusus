/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 20:35:29 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/10 16:33:13 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned int i;

	if (dst == src)
		return (dst);
	if (len > 0)
	{
		if (dst < src)
		{
			i = -1;
			while (++i < len)
				*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		}
		else
		{
			i = len - 1;
			while (i > 0)
			{
				*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
				i--;
			}
			*(unsigned char *)(dst) = *(unsigned char *)(src);
		}
	}
	return (dst);
}
