/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:10:58 by eina              #+#    #+#             */
/*   Updated: 2026/03/11 09:39:00 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_valid_hex(char *p)
{
	int	has_digit;

	has_digit = 0;
	if (!*p || *p == ' ' || *p == '\n')
		return (0);
	if (*p == '0' && (*(p + 1) == 'x' || *(p + 1) == 'X'))
		p += 2;
	if (!*p || *p == ' ' || *p == '\n')
		return (0);
	while (*p && *p != ' ' && *p != '\n')
	{
		if (!ft_isdigit((unsigned char)*p) && !(*p >= 'a' && *p <= 'f')
			&& !(*p >= 'A' && *p <= 'F'))
			return (0);
		has_digit = 1;
		p++;
	}
	return (has_digit);
}

static int	is_valid_int(char *p)
{
	if (*p == '-' || *p == '+')
		p++;
	if (!*p || !ft_isdigit((unsigned char)*p))
		return (0);
	while (ft_isdigit((unsigned char)*p))
		p++;
	if (*p && *p != ' ' && *p != ',' && *p != '\n')
		return (0);
	return (1);
}

static int	parse_hex(char *p)
{
	int	result;
	int	digit;

	result = 0;
	if (*p == '0' && (*(p + 1) == 'x' || *(p + 1) == 'X'))
		p += 2;
	while (*p && *p != ' ' && *p != '\n')
	{
		if (*p >= '0' && *p <= '9')
			digit = *p - '0';
		else if (*p >= 'a' && *p <= 'f')
			digit = *p - 'a' + 10;
		else
			digit = *p - 'A' + 10;
		result = result * 16 + digit;
		p++;
	}
	return (result);
}

static int	skip_color(char **p, int *color)
{
	if (!is_valid_hex(*p))
		return (print_error("Invalid token"), 0);
	*color = parse_hex(*p);
	while (**p && **p != ' ' && **p != '\n')
		(*p)++;
	return (1);
}

int	validate_token(char **p, int *z_val, int *color_val)
{
	if (!is_valid_int(*p))
		return (print_error("Invalid token"), 0);
	*z_val = ft_atoi(*p);
	while (**p && **p != ' ' && **p != ',' && **p != '\n')
		(*p)++;
	if (**p == ',')
	{
		(*p)++;
		if (!**p || **p == ' ' || **p == '\n')
			return (print_error("Invalid token"), 0);
		if (!skip_color(p, color_val))
			return (0);
	}
	else if (!**p || **p == ' ' || **p == '\n')
		*color_val = 0xFFFFFF;
	else
		return (print_error("Invalid token"), 0);
	while (**p == ' ')
		(*p)++;
	return (1);
}
