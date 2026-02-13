/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:24:22 by eina              #+#    #+#             */
/*   Updated: 2026/02/13 17:42:18 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**allocatemap(t_map *map, char *line)
{
	int	x;
	int	y;
	int	*row;

	map->z = ft_calloc(sizeof(int *), map->height);
	if (!map->z)
	{
		error("map allocation failed");
		return (-1);
	}
	y = 0;
	while (y < map->height)
	{
		map->z[y] = ft_calloc(sizeof(int), map->width);
		x = 0;
		map->z[y] = ft_split(line, ' ');
		while (map->z[y][x])
		{			
			map->z[y][x] = ft_atoi(map->z[y][x]);
			x++;
		}
		y++;
	}
}

int	parse_map(int fd, t_map *map)
{
	int		len;
	char	*line;

	line = get_next_line(fd);
	if (!line || line[0] == '\0')
	{
		error("Empty file");
		return (-1);
	}
	map->width = ft_strlen(line);
	if (map->width > 0 && line[map->width - 1] == '\n')
	{
		map->width--;
		map->height = 1;
		allocatemap(map, line);
	}
	while (line = get_next_line(fd) != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		if (len != map->width)
		{
			error("Map is not rectangular");
			return (-1);
		}
		map->height++;
		allocatemap(map, line);
		free(line);
	}
	return (1);
}
