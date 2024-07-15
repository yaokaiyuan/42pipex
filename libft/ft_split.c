/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:22:01 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/03/04 00:56:30 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_malloc(char **word_i, int position, size_t buffer)
{
	int		i;

	i = 0;
	word_i[position] = malloc(buffer);
	if (word_i[position] == NULL)
	{
		while (i < position)
			free(word_i[i++]);
		free(word_i);
		return (1);
	}
	return (0);
}

static int	sepandfill(char **word_i, char const *s, char separator)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == separator && *s)
			s++;
		while (*s != separator && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (free_malloc(word_i, i, len + 1))
				return (1);
			ft_strlcpy(word_i[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

static size_t	count_words(char const *s, char separator)
{
	size_t	words;
	int		inside_words;

	words = 0;
	while (*s)
	{
		while (*s == separator && *s)
			s++;
		inside_words = 0;
		while (*s != separator && *s)
		{
			if (!inside_words)
			{
				words++;
				inside_words = 1;
			}
			s++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**word_i;

	if (s == NULL)
		return (NULL);
	words = 0;
	words = count_words(s, c);
	word_i = malloc((words + 1) * sizeof(char *));
	if (word_i == NULL)
		return (NULL);
	word_i[words] = NULL;
	if (sepandfill(word_i, s, c))
		return (NULL);
	return (word_i);
}
