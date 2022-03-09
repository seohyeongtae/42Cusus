# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 09:55:53 by hyseo             #+#    #+#              #
#    Updated: 2022/03/10 02:12:55 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= c++
CFLAGS = -Wall -Werror -Wextra
RM	= rm -rf

NAME	= bsp
HEADER 	= Fixed.hpp	\
		Point.hpp
OBJS	= Fixed.o	\
		Point.o	\
		bsp.o		\
		main.o	\

all : $(NAME)

%.o : %.c $(HEADER) 
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) 
		$(CC) $(CFLAGS) -o $@ $^

clean : 
		$(RM) $(OBJS) *.replace

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all
