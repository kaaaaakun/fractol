NAME = fractal

SRCS =	main.c\
		fractal.c\
		make_set.c\
		fractal_utils.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

MINILIBX	=	libmlx.dylib

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(OBJS) $(CFLAGS) $(MINILIBX) -o $@

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(DEBUG):
	make all
	$(CC) $(OBJS) $(CFLAGS_DEBUG) $(MINILIBX) -o $(NAME)

clean:
	$(RM) $(OBJS) $(B_OBJS)	

fclean: clean
	$(RM) $(NAME)

re: fclean all
