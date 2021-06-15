/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:34:00 by hyseo             #+#    #+#             */
/*   Updated: 2021/05/31 19:28:57 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20000
# endif

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

unsigned int	ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, unsigned int c);
char			*set_line (char **line, char *backup, char *backnewline);
int				count_line(char *backup);
int				check_line (char **line, char **backup, char *backnewline);
int				get_next_line(int fd, char **line);

#endif
