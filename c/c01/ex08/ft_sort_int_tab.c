/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 04:08:14 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/04 04:42:49 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int		c;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				c = tab[j];
				tab[j] = tab[i];
				tab[i] = c;
			}
			j++;
		}
		i++;
	}
}

int		main(void)
{
	int a[5]={5,3,1,4,6};

	ft_sort_int_tab(a,5);
	int i =0;
	while (i < 5)
	{
		printf("%d", a[i]);
		i++;
	}
	return 0;
}
