/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:31:33 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/07 11:51:13 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex(unsigned int s)
{
	char a;

	a = (char)s;
	if (s >= 0 && s <= 9)
	{
		a += 48;
		write(1, &a, 1);
	}
	else
	{
		a += 87;
		write(1, &a, 1);
	}
}

void	ft_putstr_hex(unsigned char str)
{
	write(1, "\\", 1);
	ft_print_hex(str / 16);
	ft_print_hex(str % 16);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	result;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putstr_hex(str[i]);
		}
		else
		{
			result = str[i];
			write(1, &result, 1);
		}
		i++;
	}
}
