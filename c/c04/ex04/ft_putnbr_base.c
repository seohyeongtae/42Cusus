/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:41:08 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/12 13:13:57 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*g_base;
int		g_len;

void	ft_print(char str)
{
	write(1, &str, 1);
}

void	ft_chage_num(long nbr)
{
	if (nbr == 0)
		return ;
	ft_chage_num(nbr / g_len);
	ft_print(g_base[nbr % g_len]);
}

int		ft_check_base(char *base)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (base[i])
	{
		j = 0;
		while (g_base[j])
		{
			if (g_base[j] == base[i])
			{
				count++;
				if (count > g_len)
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	nnbr;

	i = 0;
	nnbr = (long)nbr;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		i++;
	}
	g_len = i;
	g_base = base;
	if (!ft_check_base(base) || i <= 1)
		return ;
	if (nbr == 0)
		write(1, "0", 1);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nnbr = -nnbr;
	}
	ft_chage_num(nnbr);
}
