/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:04:26 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/26 16:05:50 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	*ft_word_make(char *word, char const *s, int k, int word_len)
{
	int		i;

	i = 0;
	while (word_len > 0)
		word[i++] = s[k - word_len--];
	word[i] = '\0';
	return (word);
}

char	**make_free(char **result, int i)
{
	while (i - 1 >= 0)
	{
		free(result[i - 1]);
		i--;
	}
	free(result);
	return (0);
}

char	**ft_split2(char **result, char const *s, char c, int word_num)
{
	int		i;
	int		k;
	int		word_len;

	i = 0;
	k = 0;
	word_len = 0;
	while (s[k] && i < word_num)
	{
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
		{
			k++;
			word_len++;
		}
		if (!(result[i] = (char *)malloc(sizeof(char) * (word_len + 1))))
			return (make_free(result, i));
		ft_word_make(result[i], s, k, word_len);
		word_len = 0;
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		word_num;
	char	**result;

	if (s == 0)
		return (0);
	word_num = ft_word_count(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (word_num + 1))))
		return (0);
	ft_split2(result, s, c, word_num);
	return (result);
}
