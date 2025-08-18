/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:55:23 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/02 08:24:08 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Searches for c in the memory location pointed to by s. Returns a pointer to
the first occurrence of c if found. Returns null if c is not found, or if n
is set to 0;
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sptr;
	unsigned char		uc;
	size_t				i;

	if (n == 0)
		return (NULL);
	sptr = s;
	uc = c;
	i = 0;
	while (i < n)
	{
		if (*(sptr + i) == uc)
		{
			return ((void *)sptr + i);
		}
		i++;
	}
	return (NULL);
}
