/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:21:36 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/14 16:40:33 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_check_base_overlap(char *src, int len)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (src[i])
	{
		j = 0;
		while (src[j])
		{
			if (src[i] == src[j])
			{
				count++;
				if (count > len)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_base(char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		if (src[i] == '+' || src[i] == '-')
			return (1);
		i++;
	}
	if (i <= 1)
		return (1);
	if (ft_check_base_overlap(src, i))
		return (1);
	return (0);
}
