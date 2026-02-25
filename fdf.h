/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:35:40 by eina              #+#    #+#             */
/*   Updated: 2026/02/25 10:33:53 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 800
# define HEIGHT 600

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 61
# define KEY_MINUS 45

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "libftprintf/ft_printf.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		width;
	int		height;
	int		**z;
}			t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}			t_point;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	// void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	float	zoom;
	float	z_scale;
	float	angle;
	int		color;
	int		min_z;
	int		max_z;
	int		offset_x;
	int		offset_y;
	t_map	map;
	t_img	img;
}			t_fdf;

int			parse_map(char *data, t_map *map);
int			validate_args(char *file);
void		print_error(char *msg);
int			*error_ret_null(char *msg);
int			error_ret_int(char *msg);
char		*free_int_matrix(int **arr, int count);
char		*free_char_matrix(char **arr, int count);
char		*free_map(t_map *map);

void		put_pixel(t_fdf *fdf, int x, int y, int color);
t_point		project(t_fdf *fdf, int x, int y);
void		compute_z_range(t_fdf *fdf);
void		draw_line(t_fdf *fdf, t_point a, t_point b, int color);
void		draw_grid(t_fdf *fdf);

void		cleanup_fdf(t_fdf *fdf);

#endif