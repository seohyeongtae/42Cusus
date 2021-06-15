/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:25:02 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/10 15:42:33 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_print_d(char *result, t_flag t, int len, int str_len)
{
	char	*re;
	int		i;
	char	zero;

	i = -1;
	if (!(re = (char *)malloc(len + 1)))
		return (0);
	if (t.flag_minus == 1)
	{
		while (++i < str_len)
			re[i] = *result++;
		while (len > i)
			re[i++] = ' ';
	}
	else if (t.flag_minus == 0)
	{
		zero = set_zero(t, result);
		while (++i < len - str_len)
			re[i] = zero;
		while (i < len)
			re[i++] = *result++;
	}
	re[i] = '\0';
	free((result - str_len));
	return (re);
}

char	*set_print_d(char *result, int str_len)
{
	char	*re;
	int		i;
	int		j;

	if (!(re = (char *)malloc(str_len + 1)))
		return (0);
	i = 0;
	j = str_len - ft_strlen(result);
	while (i < j)
	{
		re[i] = '0';
		i++;
	}
	j = 0;
	while (i < str_len)
	{
		re[i] = result[j];
		i++;
		j++;
	}
	re[i] = '\0';
	return (re);
}

int		count_min(char *print_result)
{
	int	i;

	i = 0;
	while (print_result[i] == ' ')
		i++;
	if (i == 0)
		i += 1;
	return (i);
}

int		print_final(char *print_result, t_flag t, int re_count, int i)
{
	if (t.flag_dot == 1 && print_result[0] == '0' && t.precision == 0)
		print_result[0] = ' ';
	if (t.d_minus == 0)
	{
		while (print_result[i])
			re_count = put_char(print_result[i++], re_count);
	}
	if (t.d_minus == 1)
	{
		if (t.precision >= t.width)
			re_count = put_char('-', re_count);
		else if (t.width > t.precision && t.flag_minus == 1)
		{
			re_count = put_char('-', re_count);
			print_result[ft_strlen(print_result) - 1] = '\0';
		}
		else
			print_result[count_min(print_result) - 1] = '-';
		while (print_result[i])
			re_count = put_char(print_result[i++], re_count);
	}
	return (re_count);
}

int		print_d(int result, t_flag t, int re_count)
{
	char	*print_result;
	int		len;
	int		str_len;
	int		i;
	char	*m_free;

	i = 0;
	if (result < 0)
	{
		result *= -1;
		t.d_minus = 1;
	}
	m_free = ft_itoa(result);
	str_len = ft_strlen(m_free);
	if (t.precision == 0 && t.flag_dot == 1 && result == 0 && t.width == 0)
		return (re_count);
	set_pre(result, &t, str_len);
	len = (t.width >= t.precision ? t.width : t.precision);
	print_result = check_print_d(
		set_print_d(m_free, t.precision), t, len, t.precision);
	re_count = print_final(print_result, t, re_count, 0);
	free(print_result);
	free(m_free);
	return (re_count);
}
