/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:58:16 by eina              #+#    #+#             */
/*   Updated: 2026/03/17 16:15:04 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*free_str(char *s)
{
	if (s)
		free(s);
	return (NULL);
}

t_row	*free_row(t_row *row, int free_payload)
{
	if (!row)
		return (NULL);
	if (free_payload)
	{
		if (row->z)
			free(row->z);
		if (row->color)
			free(row->color);
	}
	free(row);
	return (NULL);
}

char	*free_int_matrix(int **arr, int count)
{
	int	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	*free_char_matrix(char **arr, int count)
{
	int	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void	free_row_array(t_row **rows, int count, int errflag)
{
	int	i;

	if (!rows)
		return ;
	i = 0;
	while (i < count)
	{
		if (errflag == -1)
			rows[i] = free_row(rows[i], 1);
		else
			rows[i] = free_row(rows[i], 0);
		i++;
	}
	free(rows);
}
