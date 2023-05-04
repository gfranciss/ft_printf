NAME = ft_printf.a

SRCS = ft_printf_part1.c\
		ft_printf.c

INCLUDE = ft_printf.h

OBJ = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror  

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		ar -rcs $(NAME) $(OBJ)


%.o: %.c $(INCLUDE)
		$(CC) $(CFLAGS) -c $< -o $@

clean: 
		rm -rf $(OBJ)

fclean:	
		rm -rf $(OBJ) $(NAME)

clear:
		clear

re: fclean all clean clear

.PHONY: all clean fclean re   