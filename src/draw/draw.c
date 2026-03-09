/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:42:56 by eina              #+#    #+#             */
/*   Updated: 2026/03/09 20:26:45 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_horizontal_segment(t_fdf *fdf, int x, int y)
{
	t_point	a;
	t_point	b;

	a = project(fdf, x, y);
	b = project(fdf, x + 1, y);
	a.color = fdf->map.color[y][x];
	b.color = fdf->map.color[y][x + 1];
	draw_line(fdf, a, b);
}

static void	draw_vertical_segment(t_fdf *fdf, int x, int y)
{
	t_point	a;
	t_point	b;

	a = project(fdf, x, y);
	b = project(fdf, x, y + 1);
	a.color = fdf->map.color[y][x];
	b.color = fdf->map.color[y + 1][x];
	draw_line(fdf, a, b);
}

void	draw_grid(t_fdf *fdf)
{
	int		x;
	int		y;
	t_point	p;

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
	if (fdf->map.width == 1 && fdf->map.height == 1)
	{
		p = project(fdf, 0, 0);
		put_pixel(fdf, p.x, p.y, fdf->map.color[0][0]);
	}
}
