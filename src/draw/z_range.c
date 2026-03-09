/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_range.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:39:54 by eina              #+#    #+#             */
/*   Updated: 2026/03/05 05:23:30 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	update_z_limits(t_fdf *fdf, int z)
{
	if (z < fdf->z_min)
		fdf->z_min = z;
	if (z > fdf->z_max)
		fdf->z_max = z;
}

void	compute_z_range(t_fdf *fdf)
{
	int	x;
	int	y;
	int	z;

	fdf->z_min = 2147483647;
	fdf->z_max = -2147483648;
	y = 0;
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			z = fdf->map.z[y][x];
			update_z_limits(fdf, z);
			x++;
		}
		y++;
	}
	fdf->z_range = fdf->z_max - fdf->z_min;
	if (fdf->z_range > 0)
		fdf->z_scale = 1.0f / (float)fdf->z_range;
	else
		fdf->z_scale = 1.0f;
}
