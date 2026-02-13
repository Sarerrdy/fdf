/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pad_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:05:32 by eina              #+#    #+#             */
/*   Updated: 2025/11/07 12:16:15 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_pad(char padc, int len, int fd)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(padc, fd);
		i++;
	}
	return (len);
}
