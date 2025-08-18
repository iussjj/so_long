/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:49:52 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/05 10:40:05 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Fills memory location pointed to by s, with n * value c, and returns a pointer
to the location.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*newpointer;
	unsigned char	value;
	size_t			i;

	newpointer = (unsigned char *)s;
	value = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		newpointer[i] = value;
		i++;
	}
	return (s);
}
