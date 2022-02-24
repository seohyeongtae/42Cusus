# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 09:55:53 by hyseo             #+#    #+#              #
#    Updated: 2022/02/24 02:05:03 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= c++
CFLAGS = -Wall -Werror -Wextra
RM	= rm -rf

NAME	= main
OBJS	= main.o


all : $(NAME)

%.o : %.c 
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) 
		$(CC) $(CFLAGS) -o $@ $^

clean : 
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all