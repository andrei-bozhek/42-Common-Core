/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abozhek <abozhek@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 18:22:03 by abozhek           #+#    #+#             */
/*   Updated: 2026/10/08 18:35:27 by abozhek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	ft_free_words(char **words, size_t count)
{
	while (count > 0)
	{
		count--;
		free(words[count]);
	}
	free(words);
}

static int	ft_fill_words(char **words, char const *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	start;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		words[word] = ft_substr(s, start, i - start);
		if (!words[word])
		{
			ft_free_words(words, word);
			return (0);
		}
		word++;
	}
	words[word] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!words)
		return (NULL);
	if (!ft_fill_words(words, s, c))
		return (NULL);
	return (words);
}
