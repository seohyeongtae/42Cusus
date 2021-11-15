/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 07:08:45 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/14 22:29:45 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char				*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str *str;

	str = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < ac)
	{
		str[i].size = ft_strlen(av[i]);
		str[i].str = (char *)malloc(str[i].size + 1);
		str[i].copy = (char *)malloc(str[i].size + 1);
		ft_strcpy(str[i].str, av[i]);
		ft_strcpy(str[i].copy, av[i]);
		i++;
	}
	str[i].str = 0;
	return (str);
}
