/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:56:30 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/02 16:25:19 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Concatenates characters from src to the end of dst, so that the total length of
the resulting string is no more than than size - 1, and null terminates the
result. If given size is less than or equal to dlen + 1, no characters are
copied. The return value is the length of the string that the function tried
to create: if size is less than source length, return size + source length,
otherwise return destination length + source length.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
