/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:35:40 by eina              #+#    #+#             */
/*   Updated: 2026/02/18 21:35:43 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "libftprintf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int	width;
	int	height;
	int	**z;
}		t_map;

int		parse_map(char *data, t_map *map);
int		validate_args(char *file);
void	error(char *msg);
int		*error_with_nullret(char *msg);
int		error_with_intret(char *msg);
char	*ft_free(int **arr, int count);
char	*ft_free_char(char **arr, int count);
char	*ft_free_str(t_map *map);

#endif