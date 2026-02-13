/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:56:30 by eina              #+#    #+#             */
/*   Updated: 2025/10/28 22:22:54 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(va_list *args, int fd)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
