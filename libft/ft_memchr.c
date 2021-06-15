/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:28:05 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/03 21:38:40 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*result;

	result = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(result + i) == (unsigned char)c)
			return (result + i);
		i++;
	}
	return (0);
}
