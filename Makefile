NAME = fractol

SRCS =	main.c\
		fractol.c\
		make_set.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./libft
RM = rm -f
AR = ar rcs

MINILIBX	=	libmlx.dylib

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

DEBUG			= debug
CFLAGS_DEBUG	= -Wall -Wextra -Werror -g -fsanitize=address -I./libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(OBJS) $(CFLAGS) $(MINILIBX) $(LIBFT) -o $@

#$(CC) $(CFLAGS) $(SRCS) libmlx.dylib -o $(NAME)
#$(CC) $(OBJ)-lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(DEBUG):
	make all
	$(CC) $(OBJS) $(CFLAGS_DEBUG) $(LIBFT) $(MINILIBX) -o $(NAME)

$(LIBFT): 
	@make -C $(LIBFT_DIR) all

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(B_OBJS)	

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
