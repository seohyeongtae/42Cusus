/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:25:02 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/09 22:09:43 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_print_p(char *result, t_flag t, int len, int str_len)
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
		zero = ((t.flag_zero == 1 && t.flag_dot == 0) ? '0' : ' ');
		while (++i < len - str_len)
			re[i] = zero;
		while (i < len)
			re[i++] = *result++;
	}
	re[i] = '\0';
	free((result - str_len));
	return (re);
}

char	*set_print_p(char *result, int str_len)
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

int		print_p(unsigned long long result, t_flag t, int re_count)
{
	char	*print_result;
	int		len;
	int		str_len;
	int		i;
	char	*m_free;

	i = 0;
	m_free = ft_itop(result);
	str_len = ft_strlen(m_free);
	if ((t.precision != 0 && t.precision <= str_len) || t.flag_dot == 0)
		t.precision = str_len;
	else if (t.precision == 0 || t.flag_dot == 1)
		t.precision = 2;
	len = (t.width >= t.precision ? t.width : t.precision);
	print_result = check_print_p(
		set_print_p(m_free, t.precision), t, len, t.precision);
	while (print_result[i])
	{
		re_count = put_char(print_result[i], re_count);
		i++;
	}
	free(print_result);
	free(m_free);
	return (re_count);
}
