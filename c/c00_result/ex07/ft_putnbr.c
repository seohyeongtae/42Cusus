/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 01:48:54 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/05 17:50:58 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_zer;

void	ft_putchar(int nb)
{
	char	result;

	result = nb + '0';
	write(1, &result, 1);
}

void	ft_putnbr(int nb)
{
	int num;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb != 0)
		g_zer = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	num = nb % 10;
	if (g_zer == 0)
		write(1, "0", 1);
	if (nb == 0)
		return ;
	else
	{
		nb /= 10;
		ft_putnbr(nb);
	}
	ft_putchar(num);
}
int		main(void)
{
	ft_putnbr(-1);
	return (0);
}
