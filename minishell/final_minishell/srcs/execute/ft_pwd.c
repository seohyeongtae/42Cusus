/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:29 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 16:39:01 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(int fd)
{
	char	*str;

	str = getcwd(NULL, 0);
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
	free(str);
	return (1);
}
