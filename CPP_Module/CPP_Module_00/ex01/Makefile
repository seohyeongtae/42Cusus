# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 09:55:53 by hyseo             #+#    #+#              #
#    Updated: 2022/02/20 17:43:47 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= c++
CFLAGS = -Wall -Werror -Wextra
RM	= rm -rf

NAME	= phonebook
HEADER 	= phonebook.hpp
OBJS	= phonebook.o

all : $(NAME)

%.o : %.c $(HEADER) 
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) 
		$(CC) $(CFLAGS) -o $@ $^

clean : 
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean all