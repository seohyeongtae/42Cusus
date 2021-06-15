# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 16:24:21 by hyseo             #+#    #+#              #
#    Updated: 2021/05/25 15:29:01 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = get_next_line.a
HEADER = get_next_line.h
OBJS = get_next_line.o \
		get_next_line_utils.o
AR = ar -rc

all : $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all
