/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:30:21 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/10 14:57:03 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_print_c(char result, t_flag t)
{
	char	*re;
	int		i;
	int		len;

	i = -1;
	len = t.width - 1;
	if (!(re = (char *)malloc(len + 1)))
		return (0);
	if (t.flag_minus == 1)
	{
		re[0] = result;
		re[len] = '\0';
		while (len > 0)
			re[len--] = ' ';
	}
	else if (t.flag_minus == 0)
	{
		len = t.width;
		while (++i < len)
			re[i] = ' ';
		re[i - 1] = result;
		re[i] = '\0';
	}
	return (re);
}

int		print_c(int result, t_flag t, int re_count)
{
	char	*print_result;
	int		i;

	i = 0;
	if (!result)
		result = 0;
	if (t.width <= 1)
	{
		re_count = put_char(result, re_count);
		return (re_count);
	}
	print_result = check_print_c(result, t);
	while (i < t.width)
	{
		re_count = put_char(print_result[i], re_count);
		i++;
	}
	free(print_result);
	return (re_count);
}
