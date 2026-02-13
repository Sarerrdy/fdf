/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:55:23 by eina              #+#    #+#             */
/*   Updated: 2025/11/11 18:36:18 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	cleanup_and_error(va_list *args)
{
	va_end(*args);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		ret;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (!*(++format))
				return (cleanup_and_error(&args));
			ret = ft_dispatch_specifier(*format, &args);
			if (ret < 0)
				return (cleanup_and_error(&args));
			count += ret;
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
