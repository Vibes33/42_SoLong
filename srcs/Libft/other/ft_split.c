/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:00:00 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 16:00:00 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

static char	*get_word(char const *s, char c, int *start)
{
	int		end;
	char	*word;
	int		i;

	while (s[*start] == c && s[*start])
		(*start)++;
	end = *start;
	while (s[end] != c && s[end])
		end++;
	word = malloc(sizeof(char) * (end - *start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (*start < end)
		word[i++] = s[(*start)++];
	word[i] = '\0';
	return (word);
}

static void	free_split(char **split, int i)
{
	while (i > 0)
	{
		i--;
		free(split[i]);
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < words)
	{
		result[i] = get_word(s, c, &start);
		if (!result[i])
		{
			free_split(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
