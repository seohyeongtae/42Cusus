/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:16:06 by hyseo             #+#    #+#             */
/*   Updated: 2021/04/15 07:12:53 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		g_str_len;
int		g_set_len;

int		ft_find_size(char *str, char *charset)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == charset[j] && charset[j])
		{
			i++;
			j++;
		}
		if (!charset[j])
			return (i);
		i++;
	}
}
int		ft_find_end(char *str, char *charset)
{
	int i;
	int j;
	int count;
	
	i = g_str_len;
	while (i > 0)
	{
		j = g_set_len;
		while (str[i] == charset[j] && j > 0)
		{
			i--;
			j--;
			count++;
		}
		if (j < 0)
			return (count);
		i--;
		count++;
	}
}

int		ft_strlen(char *src)
{
	int i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char **result;
	char *arry;
	int i;
	int count;
	
	count = 0;
	g_str_len = ft_strlen(str);
	g_set_len = ft_strlen(charset);
	result = (char **)malloc(sizeof(char *) * (ft_strlen(str) 
				- ft_find_size(str, charset) - ft_find_end(str, charset)) + 1);
	while (*str)
	{
		i = -1;
		while(*str == charset[i++] && charset[i++])
			str++;
		if (!charset[i])
			count++;
		if (count == 2)

		str++;
	}

	return (result);
}

int		main(void)
{
	char *a = {"aaabbb vvvbb ccbbccsdfasdfbbsdfasfd"};
	char *b = {"bb"};
	
	ft_split(a,b);
	return (0);
}
