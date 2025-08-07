/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:06:36 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/04 14:06:17 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Creates a copy of the string pointed to by s, allocates memory for it, applies
function f to each character in the new string, and returns a pointer to it.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*outputstring;
	size_t	stringlength;
	size_t	i;

	if (!s || !f)
		return (NULL);
	stringlength = ft_strlen(s);
	outputstring = ft_calloc(stringlength + 1, sizeof (char));
	i = 0;
	while (i < stringlength)
	{
		outputstring[i] = f(i, s[i]);
		i++;
	}
	return (outputstring);
}
