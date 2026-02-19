/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:24:22 by eina              #+#    #+#             */
/*   Updated: 2026/02/18 22:28:08 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*allocate_map_values(char *line)
{
	char	**tmparr;
	int		*tmpline;
	int		i;

	if (!line || line[0] == '\0')
		return (error_with_nullret("Empty file during allocation"));
	tmparr = ft_split(line, ' ');
	if (!tmparr)
		return (error_with_nullret("error with split during allocation"));
	i = 0;
	while (tmparr[i])
		i++;
	tmpline = calloc(sizeof(int), i);
	if (!tmpline)
	{
		ft_free_char(tmparr, i);
		return (error_with_nullret("error with split during allocation"));
	}
	i = -1;
	while (tmparr[++i])
		tmpline[i] = ft_atoi(tmparr[i]);
	ft_free_char(tmparr, i);
	return (tmpline);
}

static int	set_width(char *line)
{
	char	**tmparr;
	int		*tmpline;
	int		i;

	if (!line || line[0] == '\0')
		return (error_with_intret("Empty file"));
	tmparr = ft_split(line, ' ');
	if (!tmparr)
		return (error_with_intret("error with split"));
	i = 0;
	while (tmparr[i])
		i++;
	tmpline = calloc(sizeof(int), i);
	if (!tmpline)
	{
		ft_free_char(tmparr, i);
		return (error_with_intret("error with split"));
	}
	i = -1;
	while (tmparr[++i])
		tmpline[i] = ft_atoi(tmparr[i]);
	free(tmpline);
	ft_free_char(tmparr, i);
	return (i);
}

static void	drain_gnl(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
}

static int	set_map_dimension(int fd, t_map *map)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	map->width = set_width(line);
	if (map->width == -1)
		return (free(line), -1);
	free(line);
	map->height = 1;
	line = get_next_line(fd);
	while (line)
	{
		len = set_width(line);
		if (len != -1 && len != map->width)
		{
			free(line);
			drain_gnl(fd);
			return (error_with_intret("Map is not square"));
		}
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	parse_map(char *data, t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(data, O_RDONLY);
	if (fd < 0)
		return (error_with_intret("cannot open map file"));
	if (set_map_dimension(fd, map) == -1)
		return (close(fd), (-1));
	close(fd);
	map->z = ft_calloc(map->height + 1, sizeof(int *));
	if (!map->z)
		return (error_with_intret("Calloc error"));
	fd = open(data, O_RDONLY);
	i = -1;
	line = get_next_line(fd);
	while (line)
	{
		map->z[++i] = allocate_map_values(line);
		if (!map->z[i])
			return (free(line), close(fd), -1);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}
