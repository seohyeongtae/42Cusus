# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 16:24:21 by hyseo             #+#    #+#              #
#    Updated: 2021/06/10 17:01:09 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
HEADER = ft_printf.h
OBJS = 	ft_strlen.o \
		ft_strdup.o \
		ft_itoa_u.o \
		ft_itoa.o \
		ft_itop.o \
		ft_itox.o \
		ft_itoxx.o \
		print_c.o \
		print_d.o \
		print_p.o \
		print_s.o \
		print_u.o \
		print_x.o \
		print_xx.o \
		print_else.o \
		ft_printf_util.o \
		set_zero.o \
		ft_printf.o
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
