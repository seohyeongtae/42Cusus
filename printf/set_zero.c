/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_zero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:19:52 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/10 15:36:50 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	set_zero(t_flag t, char *result)
{
	char	zero;

	zero = ((t.flag_zero == 1 && t.flag_dot == 0) || (t.flag_zero == 1 &&
	t.flag_dot == 1 && t.precision >= (int)ft_strlen(result)
	&& t.d_pre == 1) ? '0' : ' ');
	return (zero);
}

char	set_zero_s(t_flag t, char *result)
{
	char	zero;

	zero = ((t.flag_zero == 1 && t.flag_dot == 0) || (t.flag_zero == 1 &&
	t.flag_dot == 1 && t.precision > (int)ft_strlen(result)) ? '0' : ' ');
	return (zero);
}

void	set_pre(int result, t_flag *t, int str_len)
{
	if (t->precision < 0)
		t->d_pre = 1;
	if (t->precision == 0 && result == 0 && t->flag_dot == 1)
		t->precision = 0;
	else if (t->precision <= str_len || t->precision < 0)
		t->precision = str_len;
	return ;
}
