/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlowerhex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:50:44 by eina              #+#    #+#             */
/*   Updated: 2025/11/07 12:20:20 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printlowerhex_val(unsigned int n, int fd)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_printlowerhex_val((n / 16), 1);
	ft_putchar_fd(base[n % 16], fd);
	return (count + 1);
}

int	ft_printlowerhex(va_list *args, int fd)
{
	unsigned int	val;

	val = va_arg(*args, unsigned int);
	if (val == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	return (ft_printlowerhex_val(val, fd));
}
