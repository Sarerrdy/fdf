/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:09:51 by eina              #+#    #+#             */
/*   Updated: 2026/03/17 16:08:21 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	read_into_stash(int fd, char **databasin, char *buffer)
{
	ssize_t	read_bytes;
	char	*joined;
	char	*fallback;

	while (!*databasin || !ft_strchr(*databasin, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (read_bytes);
		buffer[read_bytes] = '\0';
		joined = ft_strjoin(*databasin, buffer);
		if (!joined)
		{
			errno = ENOMEM;
			fallback = ft_strjoin(NULL, buffer);
			if (!fallback)
				return (*databasin = ft_freeupdate(*databasin, NULL, NULL), -1);
			*databasin = ft_freeupdate(*databasin, fallback, NULL);
			return (-1);
		}
		*databasin = ft_freeupdate(*databasin, joined, NULL);
	}
	return (1);
}

static char	*extract_line_with_newline(char **databasin, char *newline)
{
	char	*line;
	char	*leftover;
	size_t	len;

	len = (size_t)(newline - *databasin) + 1;
	line = (char *)malloc(len + 1);
	if (!line)
	{
		errno = ENOMEM;
		*databasin = ft_freeupdate(*databasin, NULL, NULL);
		return (NULL);
	}
	ft_memcpy(line, *databasin, len);
	line[len] = '\0';
	leftover = ft_strjoin(NULL, newline + 1);
	if (!leftover && *(newline + 1) != '\0')
	{
		errno = ENOMEM;
		free(line);
		*databasin = ft_freeupdate(*databasin, NULL, NULL);
		return (NULL);
	}
	*databasin = ft_freeupdate(*databasin, leftover, NULL);
	return (line);
}

static char	*get_line(char **databasin)
{
	char	*newline;
	char	*line;

	if (!databasin || !*databasin || **databasin == '\0')
		return (NULL);
	newline = ft_strchr(*databasin, '\n');
	if (newline)
		return (extract_line_with_newline(databasin, newline));
	line = *databasin;
	*databasin = NULL;
	return (line);
}

static char	*get_next_line(int fd)
{
	static char	*databasin;
	char		*buffer;
	ssize_t		read_status;

	errno = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (errno = EINVAL, NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		errno = ENOMEM;
		return (databasin = ft_freeupdate(databasin, NULL, NULL), NULL);
	}
	read_status = read_into_stash(fd, &databasin, buffer);
	free(buffer);
	if (read_status < 0)
	{
		if (errno == 0)
			errno = ENOMEM;
		databasin = ft_freeupdate(databasin, NULL, NULL);
		return (NULL);
	}
	if (read_status == 0)
		return (handle_eof(&databasin));
	return (get_line(&databasin));
}

char	*gnl_with_status(int fd, int *status)
{
	char	*line;

	if (!status)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
	{
		if (errno != 0)
			*status = -1;
		else
			*status = 0;
	}
	else
		*status = 1;
	return (line);
}
