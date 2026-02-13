/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdecimals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:06:17 by eina              #+#    #+#             */
/*   Updated: 2025/10/28 22:23:02 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdecimals(va_list *args, int fd)
{
	int	sint;

	sint = va_arg(*args, int);
	ft_putnbr_fd(sint, fd);
	return (ft_int_len(sint));
}
