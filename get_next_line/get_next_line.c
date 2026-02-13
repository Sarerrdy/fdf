/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:57:39 by eina              #+#    #+#             */
/*   Updated: 2026/02/11 12:09:36 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

static char	*ft_freeupdate(char *old, char *new, char *extra)
{
	if (old)
		free(old);
	if (new && *new == '\0')
	{
		free(new);
		new = NULL;
	}
	if (extra)
		free(extra);
	return (new);
}

static char	*get_line(char **databasin)
{
	char	*newline;
	char	*line;
	char	*leftover;
	size_t	len;

	if (!databasin || !*databasin || **databasin == '\0')
		return (NULL);
	newline = ft_strchr(*databasin, '\n');
	if (newline)
	{
		len = (size_t)(newline - *databasin) + 1;
		line = (char *)malloc(len + 1);
		if (!line)
			return (NULL);
		ft_memcpy(line, *databasin, len);
		line[len] = '\0';
		leftover = ft_strjoin(NULL, newline + 1);
		*databasin = ft_freeupdate(*databasin, leftover, NULL);
		return (line);
	}
	line = *databasin;
	*databasin = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*databasin;
	ssize_t		read_bytes;
	char		*joined;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(databasin, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (ft_freeupdate(databasin, NULL, buffer));
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		joined = ft_strjoin(databasin, buffer);
		if (!joined)
			return (ft_freeupdate(databasin, NULL, buffer));
		databasin = ft_freeupdate(databasin, joined, NULL);
	}
	free(buffer);
	return (get_line(&databasin));
}
