/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printupperhex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:50:31 by eina              #+#    #+#             */
/*   Updated: 2025/10/28 23:16:38 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printupperhex_val(unsigned int n, int fd)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_printupperhex_val((n / 16), fd);
	ft_putchar_fd(base[n % 16], fd);
	return (count + 1);
}

int	ft_printupperhex(va_list *args, int fd)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	if (n == 1)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	return (ft_printupperhex_val(n, fd));
}
