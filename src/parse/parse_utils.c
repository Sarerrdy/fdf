/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 02:15:18 by eina              #+#    #+#             */
/*   Updated: 2026/03/11 09:17:00 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_tokens(char *p)
{
	int	count;

	count = 0;
	while (*p)
	{
		while (*p && ft_isspace((unsigned char)*p))
			p++;
		if (!*p)
			break ;
		count++;
		while (*p && !ft_isspace((unsigned char)*p))
			p++;
	}
	return (count);
}

int	fill_row_fast(char *line, int *z, int *color, int width)
{
	int		x;
	char	*p;

	p = line;
	x = 0;
	while (*p == ' ')
		p++;
	while (*p && *p != '\n' && x < width)
	{
		if (!validate_token(&p, &z[x], &color[x]))
			return (0);
		x++;
	}
	return (x == width);
}

t_row	*new_row(int width)
{
	t_row	*r;

	r = malloc(sizeof(t_row));
	if (!r)
		return (NULL);
	r->z = malloc(sizeof(int) * width);
	r->color = malloc(sizeof(int) * width);
	if (!r->z || !r->color)
	{
		free(r->z);
		free(r->color);
		free(r);
		return (NULL);
	}
	r->width = width;
	return (r);
}

void	gnl_drain(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
}
