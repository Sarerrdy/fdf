/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 02:07:40 by eina              #+#    #+#             */
/*   Updated: 2026/03/09 03:49:02 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *s, int base)
{
	int	val;
	int	digit;

	val = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			digit = *s - '0';
		else if (*s >= 'A' && *s <= 'F')
			digit = *s - 'A' + 10;
		else if (*s >= 'a' && *s <= 'f')
			digit = *s - 'a' + 10;
		else
			break ;
		if (digit >= base)
			break ;
		val = val * base + digit;
		s++;
	}
	return (val);
}
