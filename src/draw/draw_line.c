/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:33:03 by eina              #+#    #+#             */
/*   Updated: 2026/02/25 09:33:14 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_line(t_point a, t_point b, int v[8])
{
	v[0] = (int)a.x;
	v[1] = (int)a.y;
	v[2] = (int)b.x;
	v[3] = (int)b.y;
	v[4] = abs(v[2] - v[0]);
	v[5] = -abs(v[3] - v[1]);
	if (v[0] < v[2])
		v[6] = 1;
	else
		v[6] = -1;
	if (v[1] < v[3])
		v[7] = 1;
	else
		v[7] = -1;
}

void	draw_line(t_fdf *fdf, t_point a, t_point b, int color)
{
	int	v[8];
	int	err;
	int	e2;

	init_line(a, b, v);
	err = v[4] + v[5];
	while (1)
	{
		put_pixel(fdf, v[0], v[1], color);
		if (v[0] == v[2] && v[1] == v[3])
			break ;
		e2 = 2 * err;
		if (e2 >= v[5])
		{
			err += v[5];
			v[0] += v[6];
		}
		if (e2 <= v[4])
		{
			err += v[4];
			v[1] += v[7];
		}
	}
}
