/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:46:27 by eina              #+#    #+#             */
/*   Updated: 2025/11/17 13:45:27 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int	ft_int_len(int n);

int	ft_printchar(va_list *args, int fd);
int	ft_printdecimals(va_list *args, int fd);
int	ft_printunsignedint(va_list *args, int fd);
int	ft_printstr(va_list *args, int fd);
int	ft_printpointer(va_list *args, int fd, int basecase);
int	ft_printupperhex(va_list *args, int fd);
int	ft_printlowerhex(va_list *args, int fd);

int	ft_printf(const char *format, ...);
int	ft_dispatch_specifier(char c, va_list *args);

#endif