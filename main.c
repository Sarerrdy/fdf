/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:45:28 by eina              #+#    #+#             */
/*   Updated: 2026/02/27 16:30:14 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_defaults(t_fdf *fdf)
{
	fdf->zoom = 20;
	fdf->z_scale = 0.5;
	fdf->rot_x = 0.0f;
	fdf->rot_y = 0.0f;
	fdf->rot_z = 0.0f;
	fdf->angle = 0.523599;
	fdf->color = 0xFFFFFF;
	fdf->offset_x = WIDTH / 2;
	fdf->offset_y = HEIGHT / 3;
}

static int	close_window(t_fdf *fdf)
{
	cleanup_fdf(fdf);
	exit(0);
}

static void	redraw(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img.img, &fdf->bpp, &fdf->line_len,
			&fdf->endian);
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
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FDF");
	fdf.img.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	fdf.addr = mlx_get_data_addr(fdf.img.img, &fdf.bpp, &fdf.line_len,
			&fdf.endian);
	draw_grid(&fdf);
	mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.img, 0, 0);
	mlx_key_hook(fdf.win, handle_key, &fdf);
	mlx_hook(fdf.win, 17, 0, close_window, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
