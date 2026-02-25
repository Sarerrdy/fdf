/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:58:16 by eina              #+#    #+#             */
/*   Updated: 2026/02/25 10:34:09 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*free_int_matrix(int **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	*free_char_matrix(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	*free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->z[i++]);
	free(map->z);
	return (NULL);
}

void	cleanup_fdf(t_fdf *fdf)
{
	if (!fdf)
		return ;
	free_map(&fdf->map);
	if (fdf->img.img)
		mlx_destroy_image(fdf->mlx, fdf->img.img);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
}
