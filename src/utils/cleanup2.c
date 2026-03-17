/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:13:11 by eina              #+#    #+#             */
/*   Updated: 2026/03/17 16:13:43 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*free_map(t_map *map)
{
	int	**tmp_z;
	int	**tmp_color;
	int	height;

	if (!map)
		return (NULL);
	tmp_z = map->z;
	tmp_color = map->color;
	height = map->height;
	map->z = NULL;
	map->color = NULL;
	map->width = 0;
	map->height = 0;
	if (tmp_z)
		free_int_matrix(tmp_z, height);
	if (tmp_color)
		free_int_matrix(tmp_color, height);
	return (NULL);
}

void	cleanup_fdf(t_fdf *fdf)
{
	if (!fdf)
		return ;
	free_map(&fdf->map);
	if (fdf->img.img && fdf->mlx)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	fdf->img.img = NULL;
	if (fdf->win && fdf->mlx)
		mlx_destroy_window(fdf->mlx, fdf->win);
	fdf->win = NULL;
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	fdf->mlx = NULL;
}
