/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_len_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 07:38:32 by eina              #+#    #+#             */
/*   Updated: 2025/11/07 11:56:19 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_uint_len(unsigned int n, int base)
{
	int	len;

	if (base < 2)
		return (0);
	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}
