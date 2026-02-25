/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:42:56 by eina              #+#    #+#             */
/*   Updated: 2026/02/25 11:59:21 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	choose_color(int z)
{
	if (z == 0)
		return (0xFFFFFF);
	return (0x0000FF);
}

static void	draw_horizontal_segment(t_fdf *fdf, int x, int y)
{
	int	z1;
	int	z2;
	int	z;
	int	color;

	z1 = fdf->map.z[y][x] * fdf->z_scale;
	z2 = fdf->map.z[y][x + 1] * fdf->z_scale;
	if (z1 > z2)
		z = z1;
	else
		z = z2;
	color = choose_color(z);
	draw_line(fdf, project(fdf, x, y), project(fdf, x + 1, y), color);
}

static void	draw_vertical_segment(t_fdf *fdf, int x, int y)
{
	int	z1;
	int	z2;
	int	z;
	int	color;

	z1 = fdf->map.z[y][x] * fdf->z_scale;
	z2 = fdf->map.z[y + 1][x] * fdf->z_scale;
	if (z1 > z2)
		z = z1;
	else
		z = z2;
	color = choose_color(z);
	draw_line(fdf, project(fdf, x, y), project(fdf, x, y + 1), color);
}

void	draw_grid(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			if (x + 1 < fdf->map.width)
				draw_horizontal_segment(fdf, x, y);
			if (y + 1 < fdf->map.height)
				draw_vertical_segment(fdf, x, y);
			x++;
		}
		y++;
	}
}
