/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 08:15:10 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/02 15:20:02 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Trims all characters found in 'set' from beginning and end of 's1', and returns a
pointer to the resulting string.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmedstring;

	if (!s1 || s1 == 0 || !set || set == 0)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = (ft_strlen(s1) -1);
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	trimmedstring = (ft_substr(s1, start, ((end - start) + 1)));
	return (trimmedstring);
}
