/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:48:53 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/18 20:05:49 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_file_extension(char *string)
{
	int	last_index;

	if (ft_strlen(string) < 5)
		return (false);
	last_index = ft_strlen(string) - 1;
	if (string[last_index] == 'r' && string[last_index - 1] == 'e'
		&& string[last_index - 2] == 'b' && string[last_index - 3] == '.')
		return (true);
	else
		return (false);
}

void	read_map_file(t_data *data, char *src)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*output;
	size_t	src_fd;
	size_t	bytes_read;

	src_fd = open(src, O_RDONLY);
	bytes_read = read(src_fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	close(src_fd);
	output = ft_strdup(buffer);
	if (!output)
	{
		ft_putendl_fd(ERROR_MALLOC, 1);
		exit(EXIT_FAILURE);
	}
	data->map_array = ft_split(output, '\n');
	data->map_copy = ft_split(output, '\n');
	free(output);
	if (!data->map_array || !data->map_copy)
	{
		free_data(data);
		ft_putendl_fd(ERROR_MALLOC, 1);
		exit(EXIT_FAILURE);
	}
}

void	valid_map_chars(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
			&& map[i][j] != 'E' && map[i][j] != 'C')
			{
				free_data(data);
				ft_putendl_fd(ERROR_CHARS, 1);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	init_map_attributes(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				data->players++;
				data->ypos = i;
				data->xpos = j;
			}
			if (map[i][j] == 'E')
				data->exits++;
			if (map[i][j] == 'C')
				data->collectibles++;
			j++;
		}
		i++;
	}
	data->width = ft_strlen(map[0]);
	data->height = i;
}

void	init_data(t_data *data, char *mapfile)
{
	read_map_file(data, mapfile);
	valid_map_chars(data, data->map_array);
	init_map_attributes(data, data->map_array);
	if (!valid_rectangle(data->map_array)
		|| !valid_enclosed(data, data->map_array)
		|| !valid_objects(data)
		|| !valid_path(data->ypos, data->xpos, data->map_copy))
	{
		free_data(data);
		exit(EXIT_FAILURE);
	}
}
