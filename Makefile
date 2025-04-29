CC=cc
CFLAGS= -Wall -Wextra -Werror

SRC =	main.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		utils/handlers.c \
		utils/parser.c \
		utils/validator.c \

OBJS = $(SRC:.c=.o)
LIBFT= libft/libft.a
LIBFT_DIR= libft

NAME= fdf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make complete -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re