/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:30:49 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/02 08:28:22 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compare at most n characters of strings s1 and s2, until either
string ends in a null terminator. Return the difference between the
first non-matching characters as an int value. Const unsigned char cast
resolves esoteric bug related to non-null zero byte return values.*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1uc;
	const unsigned char	*s2uc;

	s1uc = (const unsigned char *)s1;
	s2uc = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((s1uc[i] != 0 || s2uc[i] != 0) && i < n)
	{
		if (s1uc[i] != s2uc[i])
			return (s1uc[i] - s2uc[i]);
		i++;
	}
	return (0);
}
