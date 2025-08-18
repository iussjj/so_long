/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:23:32 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/08 11:20:54 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	output_char(int *counter, unsigned int c)
{
	int	write_return;

	if (*counter == -1)
		return ;
	write_return = write(1, &c, 1);
	if (write_return == -1)
		*counter = -1;
	else
		*counter += write_return;
}

void	output_str(int *counter, char *string)
{
	if (!string)
		string = "(null)";
	while (*string != '\0' && *counter >= 0)
	{
		output_char(counter, *string);
		string++;
	}
}

void	output_unum(int *counter, char *digits, uintptr_t base,
	uintptr_t number)
{
	if (number >= base)
		output_unum(counter, digits, base, number / base);
	output_char(counter, digits[number % base]);
}

void	output_num(int *counter, char *digits, intptr_t base, intptr_t number)
{
	if (number < 0)
	{
		output_char(counter, '-');
		number *= -1;
	}
	output_unum(counter, digits, base, number);
}

void	output_ptr(int *counter, void *pointer)
{
	if (!pointer)
		return (output_str(counter, "(nil)"));
	output_str(counter, "0x");
	output_unum(counter, "0123456789abcdef", 16, (uintptr_t)pointer);
}
