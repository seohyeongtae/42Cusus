# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 16:24:21 by hyseo             #+#    #+#              #
#    Updated: 2021/07/29 14:07:33 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
HEADER = push_swap.h
OBJS = 	push_swap.o \
		make_temstack.o \
		check_pp_min.o \
		check_pp.o \
		check_sort.o \
		find_pivot.o \
		run_min.o \
		run_r.o \
		run_s_p.o \
		start_sort.o \
		ft_split.o \
		ft_strjoin.o \
		setting_stack.o 

all : $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all
