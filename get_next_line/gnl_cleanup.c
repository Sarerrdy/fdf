/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 22:55:01 by eina              #+#    #+#             */
/*   Updated: 2026/03/17 10:02:49 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_freeupdate(char *old, char *new, char *extra)
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
