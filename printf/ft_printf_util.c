/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:48:03 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/10 20:27:48 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

char			*ft_strdup(char *s1)
{
	char	*re;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	if (!(re = malloc(len + 1)))
		return (0);
	while (s1[i])
	{
		re[i] = s1[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}

t_flag			flagt(void)
{
	t_flag	t;

	t.flag_dot = 0;
	t.flag_minus = 0;
	t.flag_mul = 0;
	t.flag_zero = 0;
	t.precision = 0;
	t.retype = 0;
	t.right = 0;
	t.width = 0;
	t.d_minus = 0;
	t.d_pre = 0;
	t.s_nu = 0;
	return (t);
}

char			*setting_wp(char *result, t_flag *t, int wp)
{
	if (wp == 1)
	{
		while (*result >= '0' && *result <= '9')
		{
			t->width *= 10;
			t->width += (int)*result - '0';
			result++;
		}
	}
	if (wp == 2)
	{
		while (*result >= '0' && *result <= '9')
		{
			t->precision *= 10;
			t->precision += (int)*result - '0';
			result++;
		}
	}
	return (--result);
}

void			setting_wp_int(int result, t_flag *t, int wp)
{
	if (result < 0 && wp == 1)
	{
		t->flag_minus = 1;
		result *= -1;
	}
	if (wp == 1)
		t->width = result;
	else if (wp == 2)
		t->precision = result;
	return ;
}
