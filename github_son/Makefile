NAME = so_long
SFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit
CFLAGS = -Wall -Wextra -g
MLX = ./mlx/libmlx.a
LIBFT = Libft/libft.a
PRINTF_SRCS = ./printf/*.c
GNL_SRCS = ./gnl/get_next_line.c  ./gnl/get_next_line_utils.c
SRC = so_long.c ./map/*.c move.c load_image.c move_utils.c
CC = gcc

all: $(MLX) $(NAME)

$(NAME): $(SRC) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(SFLAGS) $(SRC) $(LIBFT) $(MLX) $(GNL_SRCS) $(PRINTF_SRCS) -o $(NAME)

$(MLX):
	make -C ./mlx

$(LIBFT):
	make -C ./Libft

$(PRINTF_SRCS):
	make -C ./printf

clean:

fclean: clean
	rm -rf $(NAME)
	make clean -C ./mlx
	make fclean -C ./libft

re: fclean all

.PHONY: clean fclean re