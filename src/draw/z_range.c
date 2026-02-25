/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_range.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:39:54 by eina              #+#    #+#             */
/*   Updated: 2026/02/25 10:19:30 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	compute_z_range(t_fdf *fdf)
{
	int y;
	int x;
	int z;

	y = 0;
	fdf->min_z = fdf->map.z[0][0];
	fdf->max_z = fdf->map.z[0][0];
	while (y < fdf->map.height)
	{
		x = 0;
		while (x < fdf->map.width)
		{
			z = fdf->map.z[y][x];
			if (z < fdf->min_z)
				fdf->min_z = z;
			if (z > fdf->max_z)
				fdf->max_z = z;
			x++;
		}
		y++;
	}
}
