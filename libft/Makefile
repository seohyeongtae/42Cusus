# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 16:24:21 by hyseo             #+#    #+#              #
#    Updated: 2021/05/20 18:13:47 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
HEADER = libft.h
OBJS = ft_atoi.o \
		ft_bzero.o \
		ft_calloc.o \
		ft_isalnum.o \
		ft_isalpha.o \
		ft_isascii.o \
		ft_isdigit.o \
		ft_isprint.o \
		ft_memccpy.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_memcpy.o \
		ft_memmove.o \
		ft_memset.o \
		ft_strchr.o \
		ft_strdup.o \
		ft_strlcat.o \
		ft_strlcpy.o \
		ft_strlen.o \
		ft_strncmp.o \
		ft_strnstr.o \
		ft_tolower.o \
		ft_toupper.o \
		ft_strjoin.o \
		ft_substr.o \
		ft_strrchr.o \
		ft_strtrim.o \
		ft_split.o \
		ft_itoa.o \
		ft_strmapi.o \
		ft_putchar_fd.o \
		ft_putstr_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o
OBJS_B = ft_lstnew.o \
		ft_lstadd_front.o \
		ft_lstlast.o \
		ft_lstsize.o \
		ft_lstadd_back.o \
		ft_lstdelone.o \
		ft_lstclear.o \
		ft_lstiter.o \
		ft_lstmap.o
AR = ar -rc

all : $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $@ $^

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

bonus : $(OBJS_B)
	$(AR) $(NAME) $^

re : fclean all

.PHONY : clean fclean all
