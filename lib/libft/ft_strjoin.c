/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:51:15 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/04 14:05:14 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstring = ft_calloc((len1 + len2 + 1), sizeof (char));
	if (!newstring)
		return (NULL);
	ft_memcpy(newstring, s1, len1);
	ft_memcpy(&newstring[len1], s2, len2);
	return (newstring);
}
