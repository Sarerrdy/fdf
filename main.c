/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.ch                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:45:28 by eina              #+#    #+#             */
/*   Updated: 2026/02/18 21:47:54 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	printmap(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_putnbr_fd(map->z[y][x], 1);
			ft_putchar_fd(' ', 1);
			x++;
		}
		ft_putchar_fd('\n', 1);
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	char	*data;

	map = (t_map){0};
	data = argv[1];
	if (argc != 2)
		return (error_with_intret("Usuage> ./program <map_file>"));
	if (!validate_args(argv[1]))
		return (error_with_intret("Invalid args"));
	if (parse_map(data, &map) != -1)
		printmap(&map);
	else
		return (-1);
	ft_free_str(&map);
	return (0);
}
