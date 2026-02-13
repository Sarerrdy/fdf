/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:50:28 by eina              #+#    #+#             */
/*   Updated: 2025/11/06 22:25:21 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printchar(va_list *args, int fd, t_fmt *fmt)
{
	int	c;
	int	len;
	int	pad;
	int	total;

	c = va_arg(*args, int);
	len = 1;
	total = 0;
	if (fmt->width > len)
		pad = fmt->width - len;
	else
		pad = 0;
	if (fmt->left)
	{
		ft_putchar_fd(c, fd);
		total = len + ft_print_pad(' ', pad, fd);
	}
	else
	{
		total = len + ft_print_pad(' ', pad, fd);
		ft_putchar_fd(c, fd);
	}
	return (total);
}
