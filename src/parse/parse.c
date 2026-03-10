/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:24:22 by eina              #+#    #+#             */
/*   Updated: 2026/03/10 13:37:39 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_row	*parse_line(char *line, int *width)
{
	int		w;
	t_row	*r;

	w = count_tokens(line);
	if (w <= 0)
		return (print_error("Invalid line"), NULL);
	if (*width == -1)
		*width = w;
	else if (w != *width)
		return (print_error("Width mismatch"), NULL);
	r = new_row(w);
	if (!r)
		return (print_error("Allocation error"), NULL);
	if (!fill_row_fast(line, r->z, r->color, w))
	{
		free(r->z);
		free(r->color);
		free(r);
		return (NULL);
	}
	return (r);
}

static int	ensure_capacity(t_row ***rows, int *cap, int height, char *line)
{
	t_row	**tmp;

	if (height < *cap)
		return (1);
	*cap *= 2;
	tmp = ft_realloc(*rows, sizeof(t_row *) * (*cap / 2), sizeof(t_row *)
			* (*cap));
	if (!tmp)
		return (free(line), print_error("Realloc failed"), -1);
	*rows = tmp;
	return (1);
}

static int	read_all_rows(int fd, t_row ***rows, t_map *m)
{
	char	*line;
	int		cap;

	cap = 1024;
	*rows = malloc(sizeof(t_row *) * cap);
	if (!*rows)
		return (print_error("Allocation error"), -1);
	line = get_next_line(fd);
	while (line)
	{
		if (ensure_capacity(rows, &cap, m->height, line) < 0)
			return (-1);
		(*rows)[m->height] = parse_line(line, &m->width);
		free(line);
		if (!(*rows)[m->height])
			return (gnl_drain(fd), -1);
		m->height++;
		line = get_next_line(fd);
	}
	return (1);
}

static int	finalize_map(t_map *m, t_row **rows)
{
	int	y;

	m->z = malloc(sizeof(int *) * m->height);
	m->color = malloc(sizeof(int *) * m->height);
	if (!m->z || !m->color)
	{
		free(m->z);
		free(m->color);
		return (print_error("Allocation error"), -1);
	}
	y = 0;
	while (y < m->height)
	{
		m->z[y] = rows[y]->z;
		m->color[y] = rows[y]->color;
		y++;
	}
	return (1);
}

int	parse_map(char *file, t_map *m)
{
	t_row	**rows;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error_ret_int("Cannot open file"));
	m->height = 0;
	m->width = -1;
	if (read_all_rows(fd, &rows, m) == -1)
		return (close(fd), free_row_array(rows, m->height, -1), -1);
	close(fd);
	if (m->height == 0 || m->width == -1)
		return (free_row_array(rows, m->height, -1), print_error("Empty map"),
			-1);
	if (finalize_map(m, rows) == -1)
		return (free_row_array(rows, m->height, -1), -1);
	return (free_row_array(rows, m->height, 0), 1);
}
