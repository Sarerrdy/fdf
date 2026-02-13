/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:24:22 by eina              #+#    #+#             */
/*   Updated: 2026/02/11 16:27:01 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_file(char *file)
{
	char	*file_name_len;
	char	*file_ext;

	file_ext = ft_strrchr(file, '.');
	file_name_len = file_ext - file;
	if (file_name_len < 1)
		return (0);
	if (ft_strncmp(".fdf", file_ext, ft_strlen(file_ext)) == 0)
		return (1);
	else
		return (0);
}
char	*parse_map(char *s_map)
{
    int fd;
    
	if (!is_valid_file(s_map))
        return (error("Invalid file name or extension"));
    fd = open(fd, O_RDONLY);
    if (fd < 0)
        return ("opening file failed");
    char *line = get_next_line(fd);
    if (!line)
        return (error("Empty file"));
    if (line[0])
        return (error("Empty line in map"));
    
}
