/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:35:54 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/02 09:01:41 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	if (n == 0)
		return (0);
	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	while (i < n)
	{
		if (*(ptr1 + i) != *(ptr2 + i))
		{
			return (*(ptr1 + i) - *(ptr2 + i));
		}
		i++;
	}
	return (0);
}
