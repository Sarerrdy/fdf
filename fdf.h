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

int		parse_map(int fd, t_map *map);
int		validate_args(char *file);
void	error(char *msg);
int		error_with_ret(char *msg);

#endif