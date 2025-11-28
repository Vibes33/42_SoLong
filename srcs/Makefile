NAME = so_long

SRCS =	main.c \
		parsing.c \
		parsing_utils.c \
		parsing_utils2.c \
		utilis.c \
		free.c \
		render.c \
		movement.c

OBJS = $(SRCS:.c=.o)
MLX = ../minilibx-linux/libmlx.a
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I../includes -I../minilibx-linux -Ilibft
LDFLAGS = -L../minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MLX) $(LDFLAGS) -o $(NAME)

$(MLX):
	make -C ../minilibx-linux

$(LIBFT):
	make -C libft

%.o: %.c ../includes/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
