/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignedint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:01:35 by eina              #+#    #+#             */
/*   Updated: 2025/11/07 12:19:28 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printunsignedint_val(unsigned int val, int fd)
{
	int	count;

	count = 0;
	if (val >= 10)
		count += ft_printunsignedint_val(val / 10, fd);
	ft_putchar_fd((val % 10) + '0', fd);
	return (count + 1);
}

int	ft_printunsignedint(va_list *args, int fd)
{
	unsigned int	val;

	val = va_arg(*args, unsigned int);
	return (ft_printunsignedint_val(val, fd));
}
