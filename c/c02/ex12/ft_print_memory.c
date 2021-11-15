/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:52:03 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/07 13:50:53 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*g_hex;

void	ft_print(char  c)
{
	write(1, &c, 1);
}

void	ft_print_hex(char c, int len)
{	
	int i;

	i = 0;
	if (len % 2 == 0 || c == '\0')
		write(1, " ", 1);
	if (c >= ' ' && c <= '~')
	{
		ft_print(g_hex[(int)c / 16]);
		ft_print(g_hex[(int)c % 16]);
	}
	else
		ft_print(' ');
}

void	ft_make_liter(unsigned char *liter)
{
	int i;

	i = 0;
	while (i < 16)
	{	
		if (liter[i])
		{
		ft_print_hex(liter[i], i);
		}
		else
			ft_print_hex('\0', 17);
		i++;
	}
	i = 0;
	write(1, " ", 1);
	while(liter[i] && i < 16)
	{	
		if (liter[i] >= ' ' && liter[i] <= '~')
			ft_print(liter[i]);
		else
			ft_print('.');
		i++;
	}
	write(1, "\n", 1);
}

void	ft_make_addr_zero(unsigned long str)
{
	int count;

	count = 0;
	while (str)
	{
		str /= 16;
		count++;
	}
	while (16 - count > 0)
	{
	   write(1, "0", 1);
	   count++;
	}
}
void	ft_make_hex_num(unsigned long str)
{
	if (str == '\0')
	{
		return;
	}
	ft_make_hex_num(str / 16);
	ft_print(g_hex[str % 16]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long memory;
	unsigned char *liter;
	int i;
	int len;

	g_hex = "0123456789abcdef";
	i = 0;
	while (size)
	{
		if (size / 16)
			len = 16;
		else
			len = size;
	memory = (unsigned long)addr + i;
	liter = (unsigned char*)addr + i;
	ft_make_addr_zero(memory);
	ft_make_hex_num(memory);
	write(1, ":", 1);
	ft_make_liter(liter);
	size -= len;
	i += 16;
	}
	return (addr);
}

int		main(void)
{
	char a[] = {"sajflkasjflkkfjslasfdfddafajflasjfB"};
	ft_print_memory(a, 50);
	return (0);
}
