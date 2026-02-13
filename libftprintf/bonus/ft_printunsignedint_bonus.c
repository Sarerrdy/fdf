/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignedint_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:01:35 by eina              #+#    #+#             */
/*   Updated: 2025/11/17 01:06:49 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_printunsignedint_val(unsigned int val, int fd)
{
	int	count;

	count = 0;
	if (val >= 10)
		count += ft_printunsignedint_val(val / 10, fd);
	ft_putchar_fd((val % 10) + '0', fd);
	return (count + 1);
}

static int	ft_uprintparser(unsigned int val, int vals[2], t_fmt *fmt, int fd)
{
	int	total;

	total = 0;
	if (!fmt->left && !(fmt->zero && fmt->precision < 0))
		total += ft_print_pad(' ', vals[1], fd);
	if (fmt->precision > vals[0])
		total += ft_print_pad('0', fmt->precision - vals[0], fd);
	else if (fmt->zero && !fmt->left)
		total += ft_print_pad('0', vals[1], fd);
	if (!(val == 0 && fmt->precision == 0))
		total += ft_printunsignedint_val(val, fd);
	if (fmt->left)
		total += ft_print_pad(' ', vals[1], fd);
	return (total);
}

int	ft_printunsignedint(va_list *args, int fd, t_fmt *fmt)
{
	unsigned int	val;
	int				numlen;
	int				len;
	int				vals[2];

	val = va_arg(*args, unsigned int);
	if (val == 0 && fmt->precision == 0)
		numlen = 0;
	else
		numlen = ft_uint_len(val, 10);
	if (fmt->precision > numlen)
		len = fmt->precision;
	else
		len = numlen;
	vals[0] = numlen;
	if (fmt->width > len)
		vals[1] = fmt->width - len;
	else
		vals[1] = 0;
	return (ft_uprintparser(val, vals, fmt, fd));
}
