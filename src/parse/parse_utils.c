/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 02:15:18 by eina              #+#    #+#             */
/*   Updated: 2026/03/09 23:17:49 by eina             ###   ########.fr       */
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

static void	skip_color(char **p, int *color)
{
	if (**p == '0' && (*p)[1] == 'x')
		*color = ft_atoi_base(*p + 2, 16);
	else
		*color = ft_atoi_base(*p, 16);
	while (**p && **p != ' ')
		(*p)++;
}

int	fill_row_fast(char *line, int *z, int *color, int width)
{
	int		x;
	char	*p;

	p = line;
	x = 0;
	while (*p == ' ')
		p++;
	while (*p && x < width)
	{
		z[x] = ft_atoi(p);
		while (*p && *p != ' ' && *p != ',')
			p++;
		if (*p == ',')
		{
			p++;
			skip_color(&p, &color[x]);
		}
		else
			color[x] = 0xFFFFFF;
		while (*p == ' ')
			p++;
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
