NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar
ARFLAGS := rcs
RM := rm -f

LIBFT_DIR := libft
INCLUDES := -I. -I$(LIBFT_DIR)

# Mandatory sources
SRC_UTILS := \
    utils/ft_dispatch_specifier.c \
    utils/ft_int_len.c \
    utils/ft_printchar.c \
    utils/ft_printdecimals.c \
    utils/ft_printlowerhex.c \
    utils/ft_printpointer.c \
    utils/ft_printstr.c \
    utils/ft_printunsignedint.c \
    utils/ft_printupperhex.c

SRCS := ft_printf.c $(SRC_UTILS)
OBJS := $(SRCS:.c=.o)

# Bonus sources
SRC_BONUS := \
    bonus/ft_dispatch_specifier_bonus.c \
    bonus/ft_print_pad_bonus.c \
    bonus/ft_printchar_bonus.c \
    bonus/ft_int_len_bonus.c \
    bonus/ft_printdecimals_bonus.c \
    bonus/ft_printlowerhex_bonus.c \
    bonus/ft_printpointer_bonus.c \
    bonus/ft_printstr_bonus.c \
    bonus/ft_printunsignedint_bonus.c \
    bonus/ft_printupperhex_bonus.c \
    bonus/ft_uint_len_bonus.c

SRCS_B := ft_printf_bonus.c $(SRC_BONUS)
BONUS_OBJS := $(SRCS_B:.c=.o)

# Marker files
MANDATORY_MARKER := .mandatory_build
BONUS_MARKER := .bonus_build

.PHONY: all bonus clean fclean re libft

# Default build: mandatory
all: libft $(MANDATORY_MARKER)

# Bonus build
bonus: libft $(BONUS_MARKER)

# Mandatory build rule (marker runs ar)
$(MANDATORY_MARKER): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $^ $(LIBFT_DIR)/*.o
	@touch $@
	@$(RM) $(BONUS_MARKER)

# Bonus build rule (marker runs ar)
$(BONUS_MARKER): $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $^ $(LIBFT_DIR)/*.o
	@touch $@
	@$(RM) $(MANDATORY_MARKER)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus/%.o: bonus/%.c ft_printf_bonus.h
	$(CC) $(CFLAGS) -DBONUS $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(MANDATORY_MARKER) $(BONUS_MARKER)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all