NAME 		= libftprintf.a
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
INCLUDE 	= include/ft_printf.h
SRC_DIR 	= ./src

SRCS = src/ft_printf.c\
		src/ft_putchar.c\
		src/ft_putnbr_hx.c\
		src/ft_putnbr.c\
		src/ft_putptr.c\
		src/ft_putunnbr.c\
		src/ft_strcpy.c\
		src/ft_putstr.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		ar -rcs $(NAME) $(OBJ)

%.o: $(SRC_DIR)/%.c $(INCLUDE)
		@$(CC) $(CFLAGS) -c $< -o $@

clean: 
		rm -rf $(OBJ)

fclean:	
		rm -rf $(OBJ) $(NAME)

re: fclean all clean 

.PHONY: all clean fclean re   