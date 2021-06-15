/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:31:22 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/14 16:49:54 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	print_fd(long long num, int fd)
{
	char	pr;

	if (num >= 10)
		print_fd(num / 10, fd);
	pr = (num % 10) + '0';
	write(fd, &pr, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;

	if (!n || fd < 0)
	{
		write(fd, "0", 1);
		return ;
	}
	num = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	print_fd(num, fd);
}
