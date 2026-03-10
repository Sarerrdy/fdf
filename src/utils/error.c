/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:29:44 by eina              #+#    #+#             */
/*   Updated: 2026/03/10 15:18:50 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(char *msg)
{
	ft_putstr_fd("Error!: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

int	error_ret_int(char *msg)
{
	print_error(msg);
	return (-1);
}

int	*error_ret_null(char *msg)
{
	print_error(msg);
	return (NULL);
}

int	close_window(t_fdf *fdf)
{
	cleanup_fdf(fdf);
	exit(0);
}
