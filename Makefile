NAME = fract-ol
SRCS = fractol.c init.c mouse_keyboard.c colors.c color_util.c mandelbrot.c julia.c tricorn.c burning_ship.c utils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	   cc $(SRCS) -I fractol.h -lmlx -lXext -lX11 -lm -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
