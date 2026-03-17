/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 01:56:38 by eina              #+#    #+#             */
/*   Updated: 2026/03/14 03:39:40 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	center_point(t_fdf *fdf, t_point *p, int x, int y)
{
	int		raw_z;
	float	normalized_z;

	p->x = (x - fdf->map.width / 2.0f) * fdf->zoom;
	p->y = (y - fdf->map.height / 2.0f) * fdf->zoom;
	raw_z = fdf->map.z[y][x];
	normalized_z = (raw_z - fdf->z_min) * fdf->z_scale;
	p->z = normalized_z * fdf->zoom;
}

static void	project_iso(t_point *p, float angle)
{
	float	px;
	float	py;

	px = p->x;
	py = p->y;
	p->x = (px - py) * cos(angle);
	p->y = (px + py) * sin(angle) - p->z;
}

t_point	project(t_fdf *fdf, int x, int y)
{
	t_point	p;

	center_point(fdf, &p, x, y);
	rotate_x(&p, fdf->rot_x);
	rotate_y(&p, fdf->rot_y);
	rotate_z(&p, fdf->rot_z);
	project_iso(&p, fdf->angle);
	p.x += fdf->offset_x;
	p.y += fdf->offset_y;
	return (p);
}
