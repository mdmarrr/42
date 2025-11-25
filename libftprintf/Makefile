NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS =	ft_printf.c ft_printformat.c ft_prints.c ft_print_char.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
