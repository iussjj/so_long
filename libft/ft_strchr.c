/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:15:41 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/02 15:10:25 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	while (s[i] != 0)
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	if (ch == 0)
		return ((char *)&s[i]);
	return (NULL);
}
