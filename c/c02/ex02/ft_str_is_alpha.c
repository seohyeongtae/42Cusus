/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:55:14 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/07 16:00:03 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_alpha(char str)
{
	if ('a' <= str && 'z' >= str)
		return (1);
	if ('A' <= str && 'Z' >= str)
		return (1);
	return (0);
}

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_alpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}
