NAME      = libftprintf.a
CC        = cc
CFLAGS    = -Wall -Wextra -Werror
INCLUDE   = include/ft_printf.h
SRC_DIR   = ./src
OBJ_DIR   = ./obj

SRCS = src/ft_printf.c \
       src/ft_putchar.c \
       src/ft_putnbr_hx.c \
       src/ft_putnbr.c \
       src/ft_putptr.c \
       src/ft_putunnbr.c \
       src/ft_strcpy.c \
       src/ft_putstr.c

OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(INCLUDE)
	ar -rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
