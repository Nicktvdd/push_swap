NAME = push_swap
SRCS = input_check.c operations.c parse.c push_swap.c sort_big_stack.c sort_small_stack.c utils.c create_index.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		cc $(CFLAGS) $(LDFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
		cc $(CFLAGS) -c $< -o $@

$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
		rm -f $(OBJS)
		make -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME)
		make -C $(LIBFT_DIR) fclean

re: fclean all
