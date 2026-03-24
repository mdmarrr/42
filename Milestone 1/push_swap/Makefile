NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibft

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	\
	src/main.c \
	src/ft_error.c \
	src/ft_free.c \
	src/stack_init.c \
	src/stack_utils.c \
	src/ft_operations.c \
	src/ft_operations2.c \
	src/ft_operations3.c \
	src/ft_atoi2.c \
	src/ft_parse.c \
	src/ft_sort.c \
	src/ft_sort_three.c \
	src/ft_sort_four.c \
	src/ft_sort_five.c \
	src/index.c \
	src/big_sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
