NAME = fractal

SRCS =	main.c\
		fractal.c\
		mandelbrot.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
AR = ar rcs

all: $(NAME)

$(NAME): #$(OBJS)
	$(CC) $(CFLAGS) $(SRCS) libmlx.dylib -o $(NAME)
#$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#-lmlx -framework OpenGL -framework AppKit

.c.o:
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	$(RM) $(OBJS) $(B_OBJS)	

fclean: clean
	$(RM) $(NAME)

re: fclean all
