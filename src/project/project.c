/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 01:56:38 by eina              #+#    #+#             */
/*   Updated: 2026/02/25 11:51:18 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	project_iso(t_point *p, float angle)
{
	float	prev_x;
	float	prev_y;

	prev_x = p->x;
	prev_y = p->y;
	p->x = (prev_x - prev_y) * cos(angle);
	p->y = (prev_x + prev_y) * sin(angle) - p->z;
}

t_point	project(t_fdf *fdf, int x, int y)
{
	t_point	p;

	p.x = x * fdf->zoom;
	p.y = y * fdf->zoom;
	p.z = fdf->map.z[y][x] * fdf->z_scale;
	project_iso(&p, fdf->angle);
	p.x += fdf->offset_x;
	p.y += fdf->offset_y;
	return (p);
}
