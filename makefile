NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g

SRCS = main.c \
		parse.c \
		validate_args.c \
		ft_free.c \
		error.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

LIBFTPRINTF = libftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTPRINTF)
		$(CC) $(CFLAGS) $(OBJS)	$(LIBFT) $(LIBFTPRINTF) -o $(NAME)

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