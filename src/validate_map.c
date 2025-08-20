/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:39:12 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/20 19:55:01 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_rect(char **map)
{
	int		i;
	size_t	firstline;

	i = 1;
	firstline = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != firstline)
			return (false);
		i++;
	}
	return (true);
}

bool	valid_enclosed(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if ((i == 0 || i == data->height - 1) && map[i][j] != '1')
				return (false);
			if ((j == 0 || j == data->width - 1) && map[i][j] != '1')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	valid_objects(t_data *data)
{
	if (data->players != 1)
		return (false);
	if (data->exits != 1)
		return (false);
	if (data->collectibles == 0)
		return (false);
	return (true);
}

void	flood_fill(int y, int x, char **map)
{
	map[y][x] = 'X';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'X')
		flood_fill(y + 1, x, map);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'X')
		flood_fill(y - 1, x, map);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'X')
		flood_fill(y, x + 1, map);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'X')
		flood_fill(y, x - 1, map);
}

bool	valid_path(int y, int x, char **map)
{
	int	i;

	flood_fill(y, x, map);
	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'C') || ft_strchr(map[i], 'E'))
			return (false);
		i++;
	}
	return (true);
}
