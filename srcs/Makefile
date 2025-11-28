NAME = so_long

SRCS =	srcs/main.c

OBJS = $(SRCS:.c=.o)
MLX = ./minilibx-linux/libmlx.a
LIBFT = ./srcs/libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I/usr/include -Iminilibx-linux
LDFLAGS = -Lmlx_linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(OBJS) $(MLX) $(LIBFT) $(LDFLAGS) -o $(NAME)

$(MLX):
	make -C ./minilibx-linux

$(LIBFT):
	make -C ./srcs/libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$RM() $(OBJS)
	make clean -C ./minilibx-linux
	make clean -C ./srcs/libft

fclean: clean
	$(RM) $(NAME)
	make clean -C ./minilibx-linux
	make fclean -C ./srcs/libft

re: fclean all

.PHONY: all clean fclean re
