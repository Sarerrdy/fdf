/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:38:46 by eina              #+#    #+#             */
/*   Updated: 2026/03/09 22:38:50 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	unsigned char	*new_ptr;
	unsigned char	*old_ptr;
	size_t			i;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (!ptr)
		return (new_ptr);
	old_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < old_size && i < new_size)
	{
		new_ptr[i] = old_ptr[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}
