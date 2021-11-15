/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:57:16 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/10 19:57:43 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_count;

void	ft_putnum(int num)
{
	char a;

	a = num + '0';
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	int num;

	num = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 0)
	{
		g_count = 1;
		num = nb % 10;
		nb /= 10;
		ft_putnbr(nb);
		ft_putnum(num);
	}
	if (nb == 0 && g_count != 1)
		write(1, "0", 1);
}
