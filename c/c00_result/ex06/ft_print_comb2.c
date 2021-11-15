/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:11:56 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/05 16:49:18 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int a_num, int b_num)
{
	char	a[3];
	char	b[3];

	a[0] = '0';
	b[0] = '0';
	a[1] = a_num + '0';
	b[1] = b_num + '0';
	if ((a_num + '0') >= 10)
	{
		a[0] = (a_num / 10) + '0';
		a[1] = (a_num % 10) + '0';
	}
	if ((b_num + '0') >= 10)
	{
		b[0] = (b_num / 10) + '0';
		b[1] = (b_num % 10) + '0';
	}
	write(1, &a, 2);
	write(1, " ", 1);
	write(1, &b, 2);
	write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			if (!(a == 98 && b == 99))
			{
				ft_print(a, b);
			}
			b++;
		}
		a++;
	}
	write(1, "98", 2);
	write(1, " ", 1);
	write(1, "99", 2);
}
int 	main(void)
{
	ft_print_comb2();
}
