/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:46:27 by eina              #+#    #+#             */
/*   Updated: 2025/11/17 13:45:38 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_fmt
{
	int	left;
	int	zero;
	int	width;
	int	precision;
	int	plus;
	int	space;
	int	alt;
}		t_fmt;

int		ft_int_len(int n);
int		ft_uint_len(unsigned int n, int base);
int		ft_print_pad(char padc, int len, int fd);

int		ft_printchar(va_list *args, int fd, t_fmt *fmt);
int		ft_printdecimals(va_list *args, int fd, t_fmt *fmt);
int		ft_printunsignedint(va_list *args, int fd, t_fmt *fmt);
int		ft_printstr(va_list *args, int fd, t_fmt *fmt);
int		ft_printpointer(va_list *args, int fd, t_fmt *fmt);
int		ft_printupperhex(va_list *args, int fd, t_fmt *fmt);
int		ft_printlowerhex(va_list *args, int fd, t_fmt *fmt);

int		ft_printf(const char *format, ...);
int		ft_dispatch_specifier(char c, va_list *args, t_fmt *fmt);
#endif