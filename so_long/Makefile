# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 20:17:42 by hyseo             #+#    #+#              #
#    Updated: 2021/11/16 15:26:56 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long
HEADER = so_long.h
MLX_FLAGS = -L.. -lmlx -framework OpenGL -framework AppKit
OBJS = ft_itoa.o \
		main.o \
		make_image_win.o \
		make_map.o \
		move.o 
OBJS_B = ./bonus/ft_itoa_bonus.o \
		./bonus/main_bonus.o \
		./bonus/make_image_win_bonus.o \
		./bonus/make_map_bonus.o \
		./bonus/move_bonus.o 
ifdef WITH_BONUS
	OBJ_FILES = $(OBJS_B)
else
	OBJ_FILES = $(OBJS)
endif

all : $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS)

bonus :
	make WITH_BONUS=1

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all bonus re
