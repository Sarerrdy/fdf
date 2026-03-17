NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g

SRCS = \
    src/parse/parse.c \
    src/parse/parse_utils.c \
    src/parse/validate_tokens.c \
    src/parse/validate_args.c \
    src/draw/draw.c \
    src/draw/draw_line.c \
    src/draw/pixel.c \
    src/draw/z_range.c \
    src/project/rotate.c \
    src/project/project.c \
    src/control/control.c \
    src/utils/cleanup.c \
    src/utils/cleanup2.c \
    src/utils/error.c \
    get_next_line/get_next_line.c \
    get_next_line/get_next_line_utils.c \
    get_next_line/get_next_line_utils2.c \
    get_next_line/gnl_cleanup.c \
    main.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_HDRS = $(LIBFT_DIR)/libft.h

MLX_FLAGS = -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS)	$(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_HDRS) $(LIBFT_DIR)/Makefile
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all