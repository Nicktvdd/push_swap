NAME = push_swap
OBJS = input_check.o operations.o parse.o push_swap.o sort_big_stack.o sort_small_stack.o utils.o
SRCS = $(OBJS:.o=.c)

LIBFT_DIR = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		cc $(CFLAGS) $(LDFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

-include $(SRCS:.c=.d)

%.o: %.c
		cc $(CFLAGS) -MMD -c $< -o $@

$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
		rm -f $(OBJS) $(SRCS:.c=.d)
		make -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME)
		make -C $(LIBFT_DIR) fclean

re: fclean all
