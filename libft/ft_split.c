/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eina <eina@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:33:27 by eina              #+#    #+#             */
/*   Updated: 2026/02/11 07:58:15 by eina             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freearr(char **strarr)
{
	size_t	i;

	i = 0;
	if (!strarr)
		return ;
	while (strarr[i])
	{
		free(strarr[i]);
		i++;
	}
	free(strarr);
	return (NULL);
}

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	split_loop(const char *s, char c, char **strarr)
{
	size_t	i;
	size_t	k;
	size_t	start;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			strarr[k] = ft_substr(s, start, (i - start));
			if (!strarr[k])
			{
				strarr = freearr(strarr);
				return ;
			}
			k++;
		}
	}
	strarr[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**strarr;

	if (!s)
		return (NULL);
	strarr = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!strarr)
		return (NULL);
	split_loop(s, c, strarr);
	if (!strarr)
		return (NULL);
	return (strarr);
}
