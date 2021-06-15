/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:50:08 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/10 20:28:49 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_print_s(char *result, t_flag t, int len, char zero)
{
	char	*re;
	int		i;

	i = -1;
	if (!(re = (char *)malloc(len + 1)))
		return (0);
	if (t.flag_minus == 1)
	{
		while (++i < t.precision && *result)
			re[i] = *result++;
		while (len > i)
			re[i++] = ' ';
	}
	else if (t.flag_minus == 0)
	{
		while (++i < len - t.precision)
			re[i] = zero;
		while (i < len && *result)
		{
			re[i] = *result++;
			i++;
		}
	}
	re[i] = '\0';
	return (re);
}

char	*result_nu(char *result, t_flag *t)
{
	char	*re;

	if (!(re = (char *)malloc(7)))
		return (0);
	re[0] = '(';
	re[1] = 'n';
	re[2] = 'u';
	re[3] = 'l';
	re[4] = 'l';
	re[5] = ')';
	re[6] = '\0';
	t->s_nu = 1;
	free(result);
	return (re);
}

int		print_s(char *result, t_flag t, int re_count, int i)
{
	char	*print_result;
	int		len;
	char	zero;

	if (!result)
		result = result_nu(result, &t);
	if ((t.precision >= (int)ft_strlen(result) || t.flag_dot == 0) ||
	(t.width >= t.precision && (int)ft_strlen(result) <= t.precision)
	|| t.precision < 0)
		t.precision = (int)ft_strlen(result);
	if (t.width >= t.precision)
		len = t.width;
	else if (t.precision <= (int)ft_strlen(result) && t.flag_dot == 1)
		len = t.precision;
	else
		len = (int)ft_strlen(result);
	zero = set_zero_s(t, result);
	print_result = check_print_s(result, t, len, zero);
	while (print_result[++i])
		re_count = put_char(print_result[i], re_count);
	free(print_result);
	if (t.s_nu == 1)
		free(result);
	return (re_count);
}
