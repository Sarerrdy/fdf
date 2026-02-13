/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:54:12 by eina              #+#    #+#             */
/*   Updated: 2025/11/03 22:24:35 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printaddress(uintptr_t n, int fd, int basecase)
{
	char	*base;
	int		count;

	count = 0;
	if (basecase == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_printaddress(n / 16, fd, basecase);
	ft_putchar_fd(base[n % 16], fd);
	return (count + 1);
}

int	ft_printpointer(va_list *args, int fd, int basecase)
{
	uintptr_t	n;
	void		*ptr;

	ptr = va_arg(*args, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (ft_strlen("(nil)"));
	}
	else
	{
		n = (uintptr_t)ptr;
		ft_putstr_fd("0x", 1);
		return (2 + ft_printaddress(n, fd, basecase));
	}
}
