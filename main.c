/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:46:15 by eina              #+#    #+#             */
/*   Updated: 2026/02/13 17:27:59 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    int fd;
    t_map *map;
    
    if (argc != 2)
        return(error_with_ret("Usuage> ./program <map_file>"));
    if (!validate_args(argv[1]))
        return (error_with_ret("Invalid args"));
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (error_with_ret("cannot open map file"));
    parse_map(fd, map);
    close(fd);
    return (0);
}
