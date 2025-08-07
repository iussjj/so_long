/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:04:38 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/02 09:12:42 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Copies n bytes from memory location src to memory location dest. Memory
locations may not overlap.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destpointer;
	const unsigned char	*srcpointer;
	size_t				i;

	if (n == 0)
		return (dest);
	destpointer = dest;
	srcpointer = src;
	i = 0;
	while (i <= n - 1)
	{
		destpointer[i] = srcpointer[i];
		i++;
	}
	return (dest);
}
