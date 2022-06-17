# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 09:55:53 by hyseo             #+#    #+#              #
#    Updated: 2022/06/17 16:49:12 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= c++
FLAG = -std=c++98
CFLAGS = -Wall -Werror -Wextra
RM	= rm -rf

NAME	= array
HEADER 	= array.hpp
OBJS	= main.o 

all : $(NAME)

%.o : %.c
		$(CC) $(FLAG) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) 
		$(CC) $(FLAG) $(CFLAGS) -o $@ $^

clean : 
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all
