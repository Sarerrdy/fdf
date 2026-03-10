/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:45:28 by eina              #+#    #+#             */
/*   Updated: 2026/03/10 15:27:41 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_defaults(t_fdf *fdf)
{
	float	zoom_x;
	float	zoom_y;

	zoom_x = (float)WIDTH / (float)fdf->map.width / 2.0f;
	zoom_y = (float)HEIGHT / (float)fdf->map.height / 2.0f;
	if (zoom_x < zoom_y)
		fdf->zoom = zoom_x;
	else
		fdf->zoom = zoom_y;
	fdf->rot_x = 0.0f;
	fdf->rot_y = 0.0f;
	fdf->rot_z = 0.0f;
	fdf->angle = 0.523599f;
	fdf->offset_x = WIDTH / 2;
	fdf->offset_y = HEIGHT / 2;
	fdf->color = 0xFFFFFF;
}

static int	init_mlx(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (error_ret_int("MLX init failed"));
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	if (!fdf->win)
		return (cleanup_fdf(fdf), error_ret_int("MLX window failed"));
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img.img)
		return (cleanup_fdf(fdf), error_ret_int("MLX image failed"));
	fdf->addr = mlx_get_data_addr(fdf->img.img, &fdf->bpp, &fdf->line_len,
			&fdf->endian);
	if (!fdf->addr)
		return (cleanup_fdf(fdf), error_ret_int("MLX data addr failed"));
	return (0);
}

static void	redraw(t_fdf *fdf)
{
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img.img)
	{
		print_error("MLX image failed");
		cleanup_fdf(fdf);
		exit(1);
	}
	fdf->addr = mlx_get_data_addr(fdf->img.img, &fdf->bpp, &fdf->line_len,
			&fdf->endian);
	if (!fdf->addr)
	{
		print_error("MLX data addr failed");
		cleanup_fdf(fdf);
		exit(1);
	}
	draw_grid(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}

static int	handle_key(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
		close_window(fdf);
	handle_move(key, fdf);
	handle_zoom(key, fdf);
	handle_zscale(key, fdf);
	handle_rotation(key, fdf);
	handle_reset(key, fdf);
	redraw(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		return (error_ret_int("Usage: ./fdf <map_file>"));
	if (!validate_args(argv[1]))
		return (error_ret_int("Invalid args"));
	fdf = (t_fdf){0};
	if (parse_map(argv[1], &fdf.map) == -1)
		return (-1);
	compute_z_range(&fdf);
	init_defaults(&fdf);
	if (init_mlx(&fdf) == -1)
		return (-1);
	draw_grid(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
	mlx_key_hook(fdf.win, handle_key, &fdf);
	mlx_hook(fdf.win, 17, 0, close_window, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
