/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 23:18:16 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/14 17:50:17 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	long long i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char		*n;
	int			i;
	long long	strlen;
	char		*str;

	strlen = 0;
	if (!size)
	{
		n = (char *)malloc(1);
		n[0] = 0;
		return (n);
	}
	i = 0;
	while (i < size)
		strlen += (ft_strlen(strs[i++]));
	n = (char *)malloc(strlen + (size - 1) * ft_strlen(sep) + 1);
	str = ft_strcat(n, strs[0]);
	i = 1;
	while (i < size)
	{
		str = ft_strcat(str, sep);
		str = ft_strcat(str, strs[i++]);
	}
	str[i] = 0;
	return (n);
}
#include <stdio.h>
int main(void){
	char *arr[3] = {"abc", "def", "ghi"};
	printf("%s", ft_strjoin(3, arr, "111"));
}
