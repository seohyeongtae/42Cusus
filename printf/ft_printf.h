/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:57:31 by hyseo             #+#    #+#             */
/*   Updated: 2021/06/10 20:27:41 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flag
{
	int		flag_minus;
	int		flag_zero;
	int		flag_mul;
	int		width;
	int		flag_dot;
	int		precision;
	char	retype;
	int		right;
	int		d_minus;
	int		d_pre;
	id_t	s_nu;
}				t_flag;

t_flag			flagt(void);
unsigned int	ft_strlen(char *str);
char			*ft_strdup(char *s1);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_u(unsigned int n);
char			*ft_itox(unsigned int n);
char			*ft_itoxx(unsigned int n);
char			*ft_itop(unsigned long long n);
char			set_zero(t_flag t, char *result);
char			set_zero_s(t_flag t, char *result);
void			set_pre(int result, t_flag *t, int str_len);

char			*setting_wp(char *result, t_flag *t, int wp);
void			setting_wp_int(int result, t_flag *t, int wp);
char			*settint_type(char *result, t_flag *t);
char			*setting_t(char *result, t_flag *t, va_list *ap);
char			*check_fwt(char *result, t_flag *t, va_list *ap);
int				put_char(char result, int re_count);
int				ft_printf(const char *format, ...);

int				print_c(int result, t_flag t, int re_count);
int				print_s(char *result, t_flag t, int re_count, int i);
int				print_d(int result, t_flag t, int re_count);
int				print_u(unsigned int result, t_flag t, int re_count);
int				print_x(unsigned int result, t_flag t, int re_count);
int				print_xx(unsigned int result, t_flag t, int re_count);
int				print_p(unsigned long long result, t_flag t, int re_count);
int				print_else(t_flag t, int re_count);

#endif
