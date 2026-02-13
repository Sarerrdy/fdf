/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:56:30 by eina              #+#    #+#             */
/*   Updated: 2025/11/07 12:13:06 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_sprintparser(char *str, int len_pad[], t_fmt *fmt, int fd)
{
	int	total;
	int	len;
	int	pad;

	len = len_pad[0];
	pad = len_pad[1];
	total = 0;
	if (fmt->left)
	{
		write(fd, str, len);
		total = len + ft_print_pad(' ', pad, fd);
	}
	else
	{
		total = len + ft_print_pad(' ', pad, fd);
		write(fd, str, len);
	}
	return (total);
}

int	ft_printstr(va_list *args, int fd, t_fmt *fmt)
{
	char	*str;
	int		len;
	int		pad;
	int		len_pad[2];

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (fmt->precision >= 0 && fmt->precision < len)
		len = fmt->precision;
	if (fmt->width > len)
		pad = fmt->width - len;
	else
		pad = 0;
	len_pad[0] = len;
	len_pad[1] = pad;
	return (ft_sprintparser(str, len_pad, fmt, fd));
}
