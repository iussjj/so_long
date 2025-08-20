/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:48:53 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/20 21:43:47 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_map_chars(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P'
			&& map[i] != 'E' && map[i] != 'C' && map[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

bool	map_contiguous(char *map)
{
	int		i;
	bool	empty_nl;

	i = 0;
	empty_nl = false;
	while (map[i] != '\0')
	{
		if (map[i] == '\n' && map[i - 1] == '\n')
			empty_nl = true;
		if (empty_nl && map[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

void	init_map_arrays(t_data *data, char *map)
{
	data->map_array = ft_split(map, '\n');
	data->map_copy = ft_split(map, '\n');
	if (!data->map_array || !data->map_copy)
		nuke_everything(data, ERROR_MALLOC);
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

void	init_data(t_data *data)
{
	if (!valid_map_chars(data->source_string))
		nuke_everything(data, ERROR_CHARS);
	if (!map_contiguous(data->source_string))
		nuke_everything(data, ERROR_CONT);
	init_map_arrays(data, data->source_string);
	init_map_attributes(data, data->map_array);
	if (!valid_rect(data->map_array))
		nuke_everything(data, ERROR_RECT);
	if (!valid_enclosed(data, data->map_array))
		nuke_everything(data, ERROR_ENCLOSED);
	if (!valid_objects(data))
		nuke_everything(data, ERROR_OBJ);
	if (!valid_path(data->ypos, data->xpos, data->map_copy))
		nuke_everything(data, ERROR_PATH);
}
