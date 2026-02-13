/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:55:23 by eina              #+#    #+#             */
/*   Updated: 2025/11/17 10:09:04 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static const char	*parse_flags(const char *p, t_fmt *fmt)
{
	while (*p == '-' || *p == '0' || *p == '+' || *p == ' ' || *p == '#')
	{
		if (*p == '-')
			fmt->left = 1;
		else if (*p == '0')
			fmt->zero = 1;
		else if (*p == '+')
			fmt->plus = 1;
		else if (*p == ' ')
			fmt->space = 1;
		else if (*p == '#')
			fmt->alt = 1;
		p++;
	}
	if (fmt->left)
		fmt->zero = 0;
	return (p);
}

static const char	*parse_fmt(const char *p, t_fmt *fmt, int n)
{
	fmt->left = 0;
	fmt->zero = 0;
	fmt->plus = 0;
	fmt->space = 0;
	fmt->alt = 0;
	fmt->width = -1;
	fmt->precision = -1;
	p = parse_flags(p, fmt);
	if (ft_isdigit(*p))
	{
		n = 0;
		while (ft_isdigit(*p))
			n = n * 10 + (*p++ - '0');
		fmt->width = n;
	}
	if (*p == '.')
	{
		n = 0;
		p++;
		while (ft_isdigit(*p))
			n = n * 10 + (*p++ - '0');
		fmt->precision = n;
	}
	return (p);
}

static int	cleanup_and_error(va_list *args)
{
	va_end(*args);
	return (-1);
}

static int	parse_and_dispatch(const char **p, va_list *args, t_fmt *fmt)
{
	int	ret;
	int	n;

	n = 0;
	*p = parse_fmt(++(*p), fmt, n);
	if (!**p)
		return (cleanup_and_error(args));
	ret = ft_dispatch_specifier(**p, args, fmt);
	if (ret < 0)
		return (cleanup_and_error(args));
	(*p)++;
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		ret;
	va_list	args;
	t_fmt	fmt;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ret = parse_and_dispatch(&format, &args, &fmt);
			if (ret < 0)
				return (cleanup_and_error(&args));
			count += ret;
		}
		else
			count += write(1, format++, 1);
	}
	va_end(args);
	return (count);
}
