/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:39:12 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/18 22:03:12 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_shape(char **map)
{
	int		i;
	size_t	firstline;
	bool	rectangular;

	i = 1;
	firstline = ft_strlen(map[0]);
	rectangular = true;
	while (map[i])
	{
		if (ft_strlen(map[i]) != firstline)
			rectangular = false;
		i++;
	}
	if (firstline > 60 || i > 32)
		return (ft_putendl_fd("Error: map over max size of 60 x 32", 1), false);
	if (!rectangular)
		return (ft_putendl_fd("Error: map not rectangular!", 1), false);
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
				return (ft_putendl_fd("Error: map not enclosed!", 1), false);
			if ((j == 0 || j == data->width - 1) && map[i][j] != '1')
				return (ft_putendl_fd("Error: map not enclosed!", 1), false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	valid_objects(t_data *data)
{
	bool	error;

	error = false;
	if (data->players != 1)
	{
		ft_putendl_fd("Error: invalid player count!", 1);
		error = true;
	}
	if (data->exits != 1)
	{
		ft_putendl_fd("Error: invalid exit count!", 1);
		error = true;
	}
	if (data->collectibles == 0)
	{
		ft_putendl_fd("Error: invalid collectible count!", 1);
		error = true;
	}
	if (error == true)
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
		{
			ft_putendl_fd("Error: no possible path on map!", 1);
			return (false);
		}
		i++;
	}
	return (true);
}
