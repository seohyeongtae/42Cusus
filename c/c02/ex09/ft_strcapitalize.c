/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:08:01 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/13 07:02:03 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcap_pre(char str)
{
	if (str == ' ')
		return (1);
	if (str >= 0 && str <= 47)
		return (1);
	if (str >= 58 && str <= 64)
		return (1);
	if (str >= 91 && str <= 96)
		return (1);
	if (str >= 123 && str <= 127)
		return (1);
	return (0);
}

void	ft_setting(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] -= 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;

	ft_setting(str);
	i = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (ft_strcap_pre(str[i - 1]))
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
