/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:58:16 by eina              #+#    #+#             */
/*   Updated: 2026/03/09 02:14:34 by eina             ###   ########.fr       */
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
	{
		free(map->z[i]);
		free(map->color[i]);
		i++;
	}
	free(map->z);
	free(map->color);
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

void	free_row_array(t_row **rows, int count, int errflag)
{
	int	i;

	i = 0;
	if (errflag == -1)
	{
		while (i < count)
		{
			free(rows[i]->z);
			free(rows[i]->color);
			free(rows[i]);
			i++;
		}
		free(rows);
	}
	else
	{
		while (i < count)
		{
			free(rows[i]);
			i++;
		}
		free(rows);
	}
}
