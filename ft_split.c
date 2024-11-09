/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchik <abouchik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:10:04 by abouchik          #+#    #+#             */
/*   Updated: 2024/10/28 15:13:08 by abouchik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
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

static char	*ft_get_word(const char *s, char c, size_t *start)
{
	size_t	end;
	char	*word;

	while (s[*start] == c)
		(*start)++;
	end = *start;
	while (s[end] && s[end] != c)
		end++;
	word = malloc(sizeof(char) * (end - *start + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, &s[*start], end - *start + 1);
	*start = end;
	return (word);
}

static void	ft_free_split(char **array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	word_count;
	size_t	i;
	size_t	start;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	array = malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	i = 0;
	start = 0;
	while (i < word_count)
	{
		array[i] = ft_get_word(s, c, &start);
		if (!array[i])
		{
			ft_free_split(array, i);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}
