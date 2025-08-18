/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 08:07:47 by jjahkola          #+#    #+#             */
/*   Updated: 2025/05/05 10:32:36 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n);

char	*ft_itoa(int n)
{
	char	*outputstr;
	int		i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	outputstr = ft_calloc((count_digits(n) + 1), sizeof (char));
	if (!outputstr)
		return (NULL);
	i = count_digits(n) - 1;
	if (n < 0)
	{
		n *= -1;
		outputstr[0] = '-';
	}
	if (n == 0)
		outputstr[0] = '0';
	while (i >= 0 && n != 0)
	{
		outputstr[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (outputstr);
}

static int	count_digits(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
