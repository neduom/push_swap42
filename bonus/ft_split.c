/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moud <mel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:28:39 by mel-moud          #+#    #+#             */
/*   Updated: 2025/02/11 13:17:36 by mel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*copy(char const *start, char const *end)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(end - start + 1);
	if (!copy)
		return (NULL);
	while (start < end)
		copy[i++] = *start++;
	copy[i] = '\0';
	return (copy);
}

static char	**free_splitte(char **splitted, int i)
{
	while (i > 0)
		free(splitted[--i]);
	free(splitted);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	char		**splitted;
	char const	*start;

	if (!s)
		return (NULL);
	splitted = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			start = s;
			while (*s && *s != c)
				s++;
			splitted[i++] = copy(start, s);
			if (!splitted[i - 1])
				return (free_splitte(splitted, i), NULL);
		}
	}
	return (splitted[i] = NULL, splitted);
}
