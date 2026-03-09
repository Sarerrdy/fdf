NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g

SRCS = \
    src/parse/parse.c \
    src/parse/parse_utils.c \
    src/parse/validate_args.c \
    src/draw/draw.c \
    src/draw/draw_line.c \
    src/draw/pixel.c \
    src/draw/z_range.c \
    src/project/rotate.c \
    src/project/project.c \
    src/control/control.c \
    src/utils/cleanup.c \
    src/utils/error.c \
    get_next_line/get_next_line.c \
    get_next_line/get_next_line_utils.c \
    main.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MLX_FLAGS = -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS)	$(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
		$(MAKE) -C libft

%.o: %.c fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all