CC=cc
CFLAGS= -Wall -Wextra -Werror
MLX_FLAGS= -lXext -lX11 -lm -lz

SRC =	main.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		utils/handlers.c \
		utils/parser.c \
		utils/validator.c \
		utils/initializer.c \
		utils/event_hooks.c \
		utils/drawer.c \
		utils/utils.c \
		utils/orthographic.c \
		utils/rotation.c \

OBJS = $(SRC:.c=.o)
LIBFT= libft/libft.a
LIBFT_DIR= libft

MLX_PATH= ./mlx
MLX= $(MLX_PATH)/libmlx.a

NAME= fdf

# Colors
GREEN   = \033[0;32m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)FDF compiled$(RESET)"

$(LIBFT):
	make complete -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled$(RESET)"

$(MLX):
	make -C $(MLX_PATH)
	@echo "$(GREEN)MLX compiled$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) -I $(MLX_PATH) -I $(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MLX_PATH)

re: fclean all

.PHONY: all clean fclean re