# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 09:55:53 by hyseo             #+#    #+#              #
#    Updated: 2022/06/14 20:24:57 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= c++
FLAG = -std=c++98
CFLAGS = -Wall -Werror -Wextra
RM	= rm -rf

NAME	= Base
HEADER 	= Base.hpp
OBJS	= main.o \
		Base.o

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
