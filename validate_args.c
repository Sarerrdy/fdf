/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 18:45:39 by eina              #+#    #+#             */
/*   Updated: 2026/02/18 21:35:51 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	validate_args(char *file)
{
	int		file_name_len;
	char	*file_ext;

	file_ext = ft_strrchr(file, '.');
	if (!file_ext)
		return (0);
	file_name_len = file_ext - file;
	if (file_name_len < 1)
		return (0);
	if (ft_strncmp(".fdf", file_ext, ft_strlen(file_ext)) == 0)
		return (1);
	else
		return (0);
}
