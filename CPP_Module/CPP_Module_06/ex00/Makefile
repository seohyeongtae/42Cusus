# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 09:55:53 by hyseo             #+#    #+#              #
#    Updated: 2022/04/26 17:39:45 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= c++
FLAG = -std=c++98
CFLAGS = -Wall -Werror -Wextra
RM	= rm -rf

NAME	= Convert
HEADER 	= Convert.hpp
OBJS	= main.o \
		Convert.o

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
