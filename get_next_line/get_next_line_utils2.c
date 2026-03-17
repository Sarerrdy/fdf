/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:06:05 by eina              #+#    #+#             */
/*   Updated: 2026/03/17 14:52:59 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_eof(char **databasin)
{
	char	*line;

	if (*databasin && **databasin)
	{
		line = *databasin;
		*databasin = NULL;
		return (line);
	}
	free(*databasin);
	*databasin = NULL;
	return (NULL);
}
