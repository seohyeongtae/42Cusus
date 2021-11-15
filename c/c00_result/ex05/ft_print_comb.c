/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:57:45 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/05 16:50:20 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	first;
	char	second;
	char	third;

	first = '0';
	while ((int)first < '8')
	{
		second = (int)first + 1;
		while ((int)second < '9')
		{
			third = (int)second + 1;
			while ((int)third < '9' + 1)
			{
				write(1, &first, 1);
				write(1, &second, 1);
				write(1, &third, 1);
				if (first != '7' || second != '8' || third != '9')
					write(1, ", ", 2);
				third = (int)third + 1;
			}
			second = (int)second + 1;
		}
		first = (int)first + 1;
	}
}
int		main(void)
{
	ft_print_comb();
	return (0);
}
