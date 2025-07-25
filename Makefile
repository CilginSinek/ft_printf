NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c utils.c
CC = cc
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	/bin/rm -f  $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re