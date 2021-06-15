/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:25:02 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/10 15:34:08 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_print_x(char *result, t_flag t, int len, int str_len)
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

char	*set_print_x(char *result, int str_len)
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

int		print_x(unsigned int result, t_flag t, int re_count)
{
	char	*print_result;
	int		len;
	int		str_len;
	int		i;
	char	*m_free;

	i = 0;
	m_free = ft_itox(result);
	str_len = ft_strlen(m_free);
	set_pre(result, &t, str_len);
	len = (t.width >= t.precision ? t.width : t.precision);
	print_result = check_print_x(
		set_print_x(m_free, t.precision), t, len, t.precision);
	while (print_result[i])
	{
		re_count = put_char(print_result[i], re_count);
		i++;
	}
	free(print_result);
	free(m_free);
	return (re_count);
}
