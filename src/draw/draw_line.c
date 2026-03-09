/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:33:03 by eina              #+#    #+#             */
/*   Updated: 2026/03/09 20:30:47 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_line(t_line *l, t_point a, t_point b)
{
	l->x0 = (int)a.x;
	l->y0 = (int)a.y;
	l->x1 = (int)b.x;
	l->y1 = (int)b.y;
	l->dx = abs(l->x1 - l->x0);
	l->dy = -abs(l->y1 - l->y0);
	l->sx = (l->x0 < l->x1) - (l->x0 > l->x1);
	l->sy = (l->y0 < l->y1) - (l->y0 > l->y1);
	l->err = l->dx + l->dy;
}

static float	get_t(t_line *l, int x, int y)
{
	float	dist;
	float	total;

	if (l->dx >= -l->dy)
	{
		dist = abs(x - l->x0);
		total = (float)l->dx;
	}
	else
	{
		dist = abs(y - l->y0);
		total = (float)(-l->dy);
	}
	if (total == 0)
		return (0.0f);
	return (dist / total);
}

static int	lerp(int a, int b, float t)
{
	return ((int)(a + (b - a) * t));
}

static int	interpolate_color(int c1, int c2, float t)
{
	int	r;
	int	g;
	int	b;

	r = lerp((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, t);
	g = lerp((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, t);
	b = lerp(c1 & 0xFF, c2 & 0xFF, t);
	return ((r << 16) | (g << 8) | b);
}

void	draw_line(t_fdf *fdf, t_point a, t_point b)
{
	t_line	l;
	int		e2;
	float	t;

	init_line(&l, a, b);
	while (1)
	{
		t = get_t(&l, l.x0, l.y0);
		put_pixel(fdf, l.x0, l.y0, interpolate_color(a.color, b.color, t));
		if (l.x0 == l.x1 && l.y0 == l.y1)
			break ;
		e2 = 2 * l.err;
		if (e2 >= l.dy)
		{
			l.err += l.dy;
			l.x0 += l.sx;
		}
		if (e2 <= l.dx)
		{
			l.err += l.dx;
			l.y0 += l.sy;
		}
	}
}
