NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g

SRCS = \
    src/parse/parse.c \
    src/parse/validate_args.c \
    src/draw/draw.c \
    src/draw/draw_line.c \
    src/draw/pixel.c \
    src/draw/z_range.c \
    src/project/project.c \
    src/utils/cleanup.c \
    src/utils/error.c \
    get_next_line/get_next_line.c \
    get_next_line/get_next_line_utils.c \
    main.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

LIBFTPRINTF = libftprintf/libftprintf.a

MLX_DIR = minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -Lminilibx -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF)
		$(CC) $(CFLAGS) $(OBJS)	$(LIBFT) $(LIBFTPRINTF) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
		$(MAKE) -C libft

$(LIBFTPRINTF):
		$(MAKE)	 -C libftprintf

clean:
		rm -f $(OBJS)
		$(MAKE) -C libft clean
		$(MAKE) -C libftprintf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C libftprintf fclean

re: fclean all