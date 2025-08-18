/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:41:34 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/02 11:40:05 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Fills the memory location pointed to by s with n zero bytes.
*/

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*newpointer;
	size_t			i;

	newpointer = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		newpointer[i] = 0;
		i++;
	}
	return (s);
}
