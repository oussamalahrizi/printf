NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
SRC = $(wildcard ./ft_*.c)
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		ar -rc $(NAME) $(OBJ)

%.o: %.c
		$(CC) -I ./  $(CFLAGS) -o $@ -c $<
clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)


re: fclean all