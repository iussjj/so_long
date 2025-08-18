/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:39:36 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/02 11:04:52 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Copies n number of items from src location to dest location. In case of forward
overlap (source before destination) copies in reverse. If there is no memory
overlap or in case of backward overlap (destination before source) behaves like
memcpy and copies normally.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destpointer;
	unsigned char		*srcpointer;

	if (n == 0 || dest == src)
		return (dest);
	destpointer = (unsigned char *)dest;
	srcpointer = (unsigned char *)src;
	if (destpointer > srcpointer && destpointer < srcpointer + n)
	{
		destpointer += n;
		srcpointer += n;
		while (n--)
			*--destpointer = *--srcpointer;
	}
	else
		while (n--)
			*destpointer++ = *srcpointer++;
	return (dest);
}
