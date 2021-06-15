/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_else.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:29:01 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/10 14:58:38 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_print_e(char result, t_flag t)
{
	char	*re;
	int		i;
	int		len;
	char	zero;

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
		zero = ((t.flag_zero == 1 && t.flag_dot == 0) ? '0' : ' ');
		while (++i < len)
			re[i] = zero;
		re[i] = result;
		re[i + 1] = '\0';
	}
	return (re);
}

int		print_else(t_flag t, int re_count)
{
	int		i;
	char	result;
	char	*print_result;

	i = 0;
	result = '%';
	if (t.width <= 1)
	{
		re_count = put_char(result, re_count);
		return (re_count);
	}
	print_result = check_print_e(result, t);
	while (print_result[i])
	{
		re_count = put_char(print_result[i], re_count);
		i++;
	}
	free(print_result);
	return (re_count);
}
