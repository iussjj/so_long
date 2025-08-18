/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:22:02 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/08 11:13:00 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = gnl_linelen(s2);
	newstring = malloc((len1 + len2 + 1) * sizeof (char));
	if (!newstring)
		return (NULL);
	ft_memcpy(newstring, s1, len1);
	ft_memcpy(&newstring[len1], s2, len2);
	newstring[len1 + len2] = '\0';
	return (newstring);
}

static bool	append_to_output(char *buffer, char **output)
{
	char	*temp;

	temp = gnl_strjoin(*output, buffer);
	if (!temp)
	{
		free(*output);
		return (false);
	}
	free(*output);
	*output = temp;
	temp = NULL;
	return (true);
}

static void	update_buffer(char *buffer)
{
	char	*next_line_start;
	size_t	chars_after_newline;

	if (!ft_strchr(buffer, '\n'))
		ft_bzero(buffer, BUFFER_SIZE + 1);
	else
	{
		next_line_start = buffer + gnl_linelen(buffer);
		chars_after_newline = (BUFFER_SIZE - gnl_linelen(buffer)) + 1;
		ft_memcpy(buffer, next_line_start, chars_after_newline);
	}
}

static char	*process_buffer(char *buffer, int fd, char *output)
{
	ssize_t	bytes_read;

	while (!ft_strchr(output, '\n'))
	{
		if (ft_strlen(buffer) == 0)
		{
			ft_bzero(buffer, BUFFER_SIZE + 1);
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read == 0 && ft_strlen(output) != 0)
				return (output);
			if (bytes_read <= 0)
			{
				free(output);
				return (NULL);
			}
		}
		if (!append_to_output(buffer, &output))
			return (NULL);
		update_buffer(buffer);
	}
	return (output);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*output;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	output = malloc(1);
	if (!output)
		return (NULL);
	output[0] = '\0';
	output = process_buffer(buffer, fd, output);
	if (!output)
		return (NULL);
	if (ft_strlen(output) == 0)
	{
		free(output);
		return (NULL);
	}
	return (output);
}
