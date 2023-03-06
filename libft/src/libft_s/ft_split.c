/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:34:42 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/28 13:51:06 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const	*s, char c)
{
	size_t	words;
	int		i;

	words = 0;
	i = 0;
	if (!s)
		return (0);
	if (s[i] != c && s[i] != '\0')
	{
		i++;
		words++;
	}
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

static char	**free_split(char	**split, int i)
{
	while (i--)
		free(split[i]);
	free(split);
	return (NULL);
}

static size_t	ft_word_len(char const	*s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const	*s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	size_t	word_len;
	char	**split;

	words = ft_count_words(s, c);
	split = (char **) malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		word_len = ft_word_len(&s[j], c);
		split[i] = ft_substr(s, j, word_len);
		if (!split[i])
			return (free_split(split, i));
		j = word_len + j;
		i++;
	}
	split[words] = NULL;
	return (split);
}
