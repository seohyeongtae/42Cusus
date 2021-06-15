/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:30:56 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/19 18:24:37 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int result;
	int re;
	int de;

	result = 0;
	re = 0;
	de = 1;
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
	{
		result = c;
		while (result >= 8)
		{
			re += result % 8 * de;
			result = result / 8;
			de *= 10;
		}
		re += result % 8 * de;
		return (re);
	}
	return (0);
}
