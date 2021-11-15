CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
TARGET = libft.a

SRC = srcs
INCLU = includes

SOURCES = $(SRC)/ft_putchar.c $(SRC)/ft_swap.c $(SRC)/ft_putstr.c $(SRC)/ft_strlen.c $(SRC)/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

all : $(TARGET)

%.0: %.c
		$(CC) $(CFLAGS) $< -o $@ -I $(INCLU)

$(TARGET): $(OBJECTS)
		ar -cr &@ $(OBJECTS)

clean:
		rm -f $(OBJECTs)

fclean: clean
		rm -f $(TARGET)

re: fclean all

