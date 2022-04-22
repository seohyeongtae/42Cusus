# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 09:55:53 by hyseo             #+#    #+#              #
#    Updated: 2022/04/22 19:55:08 by hyseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= c++
FLAG = -std=c++98
CFLAGS = -Wall -Werror -Wextra
RM	= rm -rf

NAME	= Bureaucrat
HEADER 	= Bureaucrat.hpp \
		Form.hpp	\
		ShrubberyCreationForm.hpp	\
		RobotomyRequestForm.hpp		\
		PresidentialPardonForm.hpp
OBJS	= Bureaucrat.o	\
		Form.o 	\
		ShrubberyCreationForm.o	\
		RobotomyRequestForm.o	\
		PresidentialPardonForm.o	\
		main.o

all : $(NAME)

%.o : %.c $(HEADER) 
		$(CC) $(FLAG) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) 
		$(CC) $(FLAG) $(CFLAGS) -o $@ $^

clean : 
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME) *_shrubbery

re : fclean all

.PHONY : clean fclean all
