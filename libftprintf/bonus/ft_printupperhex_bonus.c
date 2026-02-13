/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printupperhex_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:50:31 by eina              #+#    #+#             */
/*   Updated: 2025/11/17 11:39:42 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_printupperhex_val(unsigned int n, int fd)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_printupperhex_val(n / 16, fd);
	ft_putchar_fd(base[n % 16], fd);
	return (count + 1);
}

static void	print_hex_prefix_upper(unsigned int val, t_fmt *fmt, int fd,
		int *total)
{
	if (fmt->alt && val != 0)
	{
		ft_putchar_fd('0', fd);
		ft_putchar_fd('X', fd);
		(*total) += 2;
	}
}

static int	ft_hexuprintparser(unsigned int val, int vals[2], t_fmt *fmt,
		int fd)
{
	int	total;

	total = 0;
	if (!fmt->left && !(fmt->zero && fmt->precision < 0))
		total += ft_print_pad(' ', vals[1], fd);
	if (fmt->alt && val != 0 && !(fmt->zero && fmt->precision < 0))
		print_hex_prefix_upper(val, fmt, fd, &total);
	if (fmt->precision > vals[0])
		total += ft_print_pad('0', fmt->precision - vals[0], fd);
	else if (fmt->zero && fmt->precision < 0 && !fmt->left)
	{
		print_hex_prefix_upper(val, fmt, fd, &total);
		total += ft_print_pad('0', vals[1], fd);
	}
	if (!(val == 0 && fmt->precision == 0))
		total += ft_printupperhex_val(val, fd);
	if (fmt->left)
		total += ft_print_pad(' ', vals[1], fd);
	return (total);
}

int	ft_printupperhex(va_list *args, int fd, t_fmt *fmt)
{
	unsigned int	val;
	int				numlen;
	int				len;
	int				vals[2];

	val = va_arg(*args, unsigned int);
	if (val == 0 && fmt->precision == 0)
		numlen = 0;
	else
		numlen = ft_uint_len(val, 16);
	len = numlen;
	if (fmt->precision > numlen)
		len = fmt->precision;
	if (fmt->alt && val != 0)
		len += 2;
	vals[0] = numlen;
	if (fmt->width > len)
		vals[1] = fmt->width - len;
	else
		vals[1] = 0;
	return (ft_hexuprintparser(val, vals, fmt, fd));
}
