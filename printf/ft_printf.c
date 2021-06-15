/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:33:41 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/10 20:27:53 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*setting_type(char *result, t_flag *t)
{
	t->right = 1;
	if (*result == 'c')
		t->retype = 'c';
	else if (*result == 's')
		t->retype = 's';
	else if (*result == 'p')
		t->retype = 'p';
	else if (*result == 'd')
		t->retype = 'd';
	else if (*result == 'i')
		t->retype = 'i';
	else if (*result == 'u')
		t->retype = 'u';
	else if (*result == 'x')
		t->retype = 'x';
	else if (*result == 'X')
		t->retype = 'X';
	else if (*result == '%')
		t->retype = 'e';
	return (result);
}

char	*setting_t(char *result, t_flag *t, va_list *ap)
{
	while (t->retype == 0 && *result)
	{
		if (*result == '-')
			t->flag_minus = 1;
		else if (*result == '0')
			t->flag_zero = 1;
		else if (*result == '*')
		{
			t->flag_mul = 1;
			if (t->flag_dot == 1)
				setting_wp_int(va_arg(*ap, int), t, 2);
			else
				setting_wp_int(va_arg(*ap, int), t, 1);
		}
		else if (*result == '.')
		{
			t->flag_dot = 1;
			result = setting_wp(result + 1, t, 2);
		}
		else if (*result >= '1' && *result <= '9' && t->flag_dot != 1)
			result = setting_wp(result, t, 1);
		result = setting_type(result, t);
		result++;
	}
	return (result);
}

int		put_char(char result, int re_count)
{
	write(1, &result, 1);
	re_count++;
	return (re_count);
}

int		result_print(va_list *ap, t_flag *t, int re_count)
{
	if (t->right == 1)
	{
		if (t->retype == 'c')
			re_count = print_c(va_arg(*ap, int), *t, re_count);
		if (t->retype == 's')
			re_count = print_s(va_arg(*ap, char *), *t, re_count, -1);
		if (t->retype == 'p')
			re_count = print_p(va_arg(*ap, unsigned long long), *t, re_count);
		if (t->retype == 'd')
			re_count = print_d(va_arg(*ap, int), *t, re_count);
		if (t->retype == 'i')
			re_count = print_d(va_arg(*ap, int), *t, re_count);
		if (t->retype == 'u')
			re_count = print_u(va_arg(*ap, unsigned int), *t, re_count);
		if (t->retype == 'x')
			re_count = print_x(va_arg(*ap, unsigned int), *t, re_count);
		if (t->retype == 'X')
			re_count = print_xx(va_arg(*ap, unsigned int), *t, re_count);
		if (t->retype == 'e')
			re_count = print_else(*t, re_count);
	}
	return (re_count);
}

int		ft_printf(const char *format, ...)
{
	char	*result;
	va_list	ap;
	t_flag	t;
	int		re_count;
	char	*refree;

	re_count = 0;
	result = ft_strdup((char *)format);
	refree = result;
	va_start(ap, format);
	while (*result)
	{
		t = flagt();
		if (*result == '%')
		{
			result = setting_t((result + 1), &t, &ap);
			re_count = result_print(&ap, &t, re_count);
		}
		if (*result && t.right == 0)
			re_count = put_char(*result++, re_count);
	}
	va_end(ap);
	free(refree);
	return (re_count);
}
