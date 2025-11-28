CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC_OTHER = other/ft_atoi.c other/ft_bzero.c other/ft_calloc.c \
			other/ft_split.c other/ft_tolower.c other/ft_toupper.c

SRC_MEM = mem/ft_memchr.c mem/ft_memcmp.c mem/ft_memcpy.c \
		  mem/ft_memmove.c mem/ft_memset.c

SRC_STR = str/ft_putstr_fd.c str/ft_strchr.c str/ft_strdup.c \
		  str/ft_striteri.c str/ft_strjoin.c str/ft_strlcat.c \
		  str/ft_strlcpy.c str/ft_strlen.c str/ft_strmapi.c \
		  str/ft_strncmp.c str/ft_strnstr.c str/ft_strrchr.c \
		  str/ft_strtrim.c str/ft_substr.c

SRC_FD = fd/ft_putchar_fd.c fd/ft_putendl_fd.c fd/ft_putnbr_fd.c

SRC_IS = ft_is/ft_isalnum.c ft_is/ft_isalpha.c ft_is/ft_isascii.c \
		 ft_is/ft_isdigit.c ft_is/ft_isprint.c

SRC_NBR = nbr/ft_itoa.c

SRC_GNL = GetNextLine/get_next_line.c

SRC_PRINTF = PrintF/ft_printf.c

SRC = $(SRC_OTHER) $(SRC_MEM) $(SRC_STR) $(SRC_FD) $(SRC_IS) $(SRC_NBR) \
	  $(SRC_GNL) $(SRC_PRINTF)

OBJ = $(SRC:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
