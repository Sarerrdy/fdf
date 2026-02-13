#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
// # include "get_next_line_bonus.h"
# include "libft/libft.h"
# include "libftprintf/ft_printf.h"
// # include "libftprintf/ft_printf_bonus.h"
# include <fcntl.h>
// # include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int	width;
	int	height;
	int	**z;
}		t_map;

char	*parse_map(char *s_map);
int		error(char *msg);

#endif