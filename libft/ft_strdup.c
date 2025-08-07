/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:04:43 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/02 15:54:43 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Creates a copy of the string pointed to by s, allocates memory for it, and 
returns a pointer to the location of the new string.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstring;
	size_t	objectsize;
	size_t	length;

	objectsize = sizeof(s[0]);
	length = ft_strlen(s);
	newstring = malloc((objectsize * length) + 1);
	if (!newstring)
		return (NULL);
	ft_memcpy(newstring, s, length);
	newstring[length] = 0;
	return (newstring);
}
