/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_specifier_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:53:49 by eina              #+#    #+#             */
/*   Updated: 2025/11/07 00:33:18 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_dispatch_specifier(char c, va_list *args, t_fmt *fmt)
{
	if (c == 'c')
		return (ft_printchar(args, 1, fmt));
	else if (c == 'd' || c == 'i')
		return (ft_printdecimals(args, 1, fmt));
	else if (c == 'u')
		return (ft_printunsignedint(args, 1, fmt));
	else if (c == 's')
		return (ft_printstr(args, 1, fmt));
	else if (c == 'p')
		return (ft_printpointer(args, 1, fmt));
	else if (c == 'x')
		return (ft_printlowerhex(args, 1, fmt));
	else if (c == 'X')
		return (ft_printupperhex(args, 1, fmt));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (-1);
}
