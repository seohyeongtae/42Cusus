/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:03:35 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/31 19:27:36 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_line(char **line, char *backup, char *backnewline)
{
	int		i;
	char	*re;
	char	*result;

	i = 0;
	re = 0;
	if (!(re = (char *)malloc(sizeof(char) * (ft_strlen(backup) -
	ft_strlen(backnewline) + 1))))
		return (0);
	while (backup[i] && (&backup[i] != backnewline))
	{
		re[i] = backup[i];
		i++;
	}
	re[i] = 0;
	*line = re;
	result = ft_strdup("");
	result = ft_strjoin(result, ft_strchr(backnewline, '\n') + 1);
	free(backup);
	return (result);
}

int		count_line(char *backup)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!backup)
		return (0);
	while (backup[i])
	{
		if (backup[i] == '\n')
			count++;
		if (count >= 2)
			return (count);
		i++;
	}
	return (count);
}

int		check_line(char **line, char **backup, char *backnewline)
{
	int	count;

	if ((count = count_line(*backup)) > 1)
		*backup = set_line(line, *backup, ft_strchr(*backup, '\n'));
	if (count == 1)
	{
		*backup = set_line(line, *backup, ft_strchr(*backup, '\n'));
		return (1);
	}
	if (backnewline)
		return (1);
	*line = ft_strdup(*backup);
	free(*backup);
	*backup = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup[OPEN_MAX];
	int			fdsize;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (backup[fd] == 0)
		backup[fd] = ft_strdup("");
	while ((fdsize = read(fd, buf, BUFFER_SIZE)))
	{
		if (fdsize == -1)
		{
			free(backup[fd]);
			return (-1);
		}
		buf[fdsize] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (ft_strchr(backup[fd], '\n'))
		{
			backup[fd] = set_line(line, backup[fd],
			ft_strchr(backup[fd], '\n'));
			return (1);
		}
	}
	return (check_line(line, &backup[fd], ft_strchr(backup[fd], '\n')));
}
