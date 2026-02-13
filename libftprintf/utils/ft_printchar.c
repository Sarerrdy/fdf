/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:50:28 by eina              #+#    #+#             */
/*   Updated: 2025/10/28 22:23:18 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(va_list *args, int fd)
{
	int	c;

	c = va_arg(*args, int);
	ft_putchar_fd(c, fd);
	return (1);
}
