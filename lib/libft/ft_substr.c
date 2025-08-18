/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:14:03 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/04 14:12:48 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Creates a new string from the part of string s beginning at index start, copying
a maximum of len number of characters and null terminating the result. Allocates
memory, and returns a pointer to the new string.

Returns an empty string if start is out of bounds. If start + len is out of 
bounds, adjusts len so the copy source is within bounds. Returns null if
len is set to 0 or if memory allocation fails;
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	source_length;

	if (!s)
		return (NULL);
	source_length = ft_strlen(s);
	if (len == 0 || start >= source_length)
		len = 0;
	else if (len > (source_length - start))
		len = (source_length - start);
	substring = malloc(len + 1);
	if (!substring)
		return (NULL);
	ft_memcpy(substring, s + start, len);
	substring[len] = 0;
	return (substring);
}
