NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -Iminilibx-linux -Isrcs/Libft

SRCS = srcs/main.c srcs/parsing.c srcs/parsing_utils.c srcs/parsing_utils2. c srcs/parsing_utils3.c srcs/utilis.c srcs/free.c srcs/render.c srcs/render_utils.c srcs/movement.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

LIBFT_DIR = srcs/Libft
LIBFT = $(LIBFT_DIR)/libft.a

LDFLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS) -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

. PHONY: all clean fclean re