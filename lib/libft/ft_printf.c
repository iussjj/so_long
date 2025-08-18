/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:55:19 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/08 11:23:59 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid_type(char c)
{
	char	*types;

	types = "csudipxX%";
	while (*types != '\0')
	{
		if (*types == c)
			return (1);
		types++;
	}
	return (0);
}

static void	select_type(int *counter, char c, va_list *args_ptr)
{
	if (c == 'c')
		output_char(counter, va_arg(*args_ptr, int));
	if (c == 's')
		output_str(counter, va_arg(*args_ptr, char *));
	if (c == 'u')
		output_unum(counter, "0123456789", 10, va_arg(*args_ptr, unsigned int));
	if (c == 'd' || c == 'i')
		output_num(counter, "0123456789", 10, va_arg(*args_ptr, int));
	if (c == 'x')
		output_unum(counter, "0123456789abcdef", 16,
			va_arg(*args_ptr, unsigned int));
	if (c == 'X')
		output_unum(counter, "0123456789ABCDEF", 16,
			va_arg(*args_ptr, unsigned int));
	if (c == 'p')
		output_ptr(counter, va_arg(*args_ptr, void *));
	if (c == '%')
		output_char(counter, '%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars_printed;

	if (!format)
		return (-1);
	va_start(args, format);
	chars_printed = 0;
	while (*format != '\0' && chars_printed >= 0)
	{
		if (*format == '%' && is_valid_type(*(format + 1)))
		{
			select_type(&chars_printed, *(format + 1), &args);
			format++;
		}
		else
			output_char(&chars_printed, *format);
		format++;
	}
	return (va_end(args), chars_printed);
}
