/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:17:15 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/02 15:49:34 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Takes a string 's' and a character 'c'. Splits the string at occurrances of 'c'
and returns a list with the resulting substrings. 
*/

#include "libft.h"

static size_t	count_words(char const *s, char c);
static char		*extract_word(char const *s, char const **sptr, char c);
static void		free_all(char **array, size_t index);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	*ptr;
	char	**strings;
	char	*newstring;

	if (!s)
		return (NULL);
	i = 0;
	ptr = (char *)s;
	strings = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	while (i < count_words(s, c))
	{
		newstring = extract_word((const char *)ptr, (const char **)&ptr, c);
		if (!newstring)
		{
			free_all(strings, i);
			return (NULL);
		}
		strings[i] = newstring;
		i++;
	}
	strings[i] = NULL;
	return (strings);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i] != 0)
	{
		if (i == 0 && s[i] != c)
			wordcount++;
		else if (s[i] != c && s[i - 1] == c)
			wordcount++;
		i++;
	}
	return (wordcount);
}

static char	*extract_word(char const *s, char const **sptr, char c)
{
	size_t	i;
	size_t	startindex;
	char	*word;

	i = 0;
	while (s[i] == c)
		i++;
	startindex = i;
	while (s[i] != c && s[i] != 0)
		i++;
	word = ft_substr(s, startindex, (i - startindex));
	if (!word)
		return (NULL);
	*sptr = s + i;
	return (word);
}

static void	free_all(char **array, size_t index)
{
	int	i;

	i = (int)index - 1;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}
