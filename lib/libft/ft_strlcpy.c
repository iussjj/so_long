/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:24:18 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/02 15:38:55 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Copies up to size - 1 characters from 'src' to 'dst', and null terminates the
result. Returns the length of the string it tried to create, ie. the length
of src, not accounting for the null terminator to be added.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	length;

	if (!src[0])
	{
		if (size > 0)
			dst[0] = '\0';
		return (0);
	}
	i = 0;
	while (src[i] != '\0')
		i++;
	length = i;
	i = 0;
	if (size == 0)
		return (length);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dst[i] != '\0')
		dst[i] = '\0';
	return (length);
}
