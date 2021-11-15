/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:22:10 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/15 01:05:35 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_print(char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		write(1, &src[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_size(int size)
{
	char a;

	if (size > 9)
	{
		ft_print_size(size / 10);
	}
	a = (size % 10) + '0';
	write(1, &a, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int			i;

	i = 0;
	while (par[i].size)
	{
		ft_print(par[i].str);
		ft_print_size(par[i].size);
		write(1, "\n", 1);
		ft_print(par[i].copy);
		i++;
	}
}
