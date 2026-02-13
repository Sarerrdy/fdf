/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:54:12 by eina              #+#    #+#             */
/*   Updated: 2025/11/07 11:56:16 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_uintptr_len(uintptr_t n, int base)
{
	int	len;

	if (base < 2)
		return (0);
	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

static int	ft_printaddress(uintptr_t n, int fd)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_printaddress(n / 16, fd);
	ft_putchar_fd(base[n % 16], fd);
	return (count + 1);
}

static int	ft_ptrprintparser(uintptr_t val, int pad, t_fmt *fmt, int fd)
{
	int	total;

	total = 0;
	if (!fmt->left)
		total += ft_print_pad(' ', pad, fd);
	ft_putstr_fd("0x", fd);
	total += 2;
	total += ft_printaddress(val, fd);
	if (fmt->left)
		total += ft_print_pad(' ', pad, fd);
	return (total);
}

int	ft_printpointer(va_list *args, int fd, t_fmt *fmt)
{
	uintptr_t	val;
	void		*ptr;
	int			len;
	int			pad;

	ptr = va_arg(*args, void *);
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", fd);
		return (ft_strlen("(nil)"));
	}
	val = (uintptr_t)ptr;
	len = ft_uintptr_len(val, 16) + 2;
	if (fmt->width > len)
		pad = fmt->width - len;
	else
		pad = 0;
	return (ft_ptrprintparser(val, pad, fmt, fd));
}
