/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:29:44 by eina              #+#    #+#             */
/*   Updated: 2026/02/13 16:54:19 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *msg)
{
	ft_putstr_fd("Error!: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd('\n', 2);
}

int	error_with_ret(char *msg)
{
	ft_putstr_fd("Error!: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd('\n', 2);
	return(-1);
}