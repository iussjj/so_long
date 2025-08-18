/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:40:37 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/18 20:04:34 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*load_texture(t_data *data, char *filepath)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(filepath);
	image = mlx_texture_to_image(data->window, texture);
	mlx_delete_texture(texture);
	if (!image)
		nuke_everything(data, ERROR_IMAGE);
	return (image);
}

void	load_images(t_data *data)
{
	data->wall = load_texture(data, "./assets/wall.png");
	data->player = load_texture(data, "./assets/player.png");
	data->collectible = load_texture(data, "./assets/collectible.png");
	data->exit_closed = load_texture(data, "./assets/exit_closed.png");
	data->exit_open = load_texture(data, "./assets/exit_open.png");
}

void	draw_instance(t_data *data, mlx_image_t *asset, int xpos, int ypos)
{
	if (mlx_image_to_window(data->window, asset,
			xpos * TILE_SIZE, ypos * TILE_SIZE) < 0)
		nuke_everything(data, ERROR_DRAW);
}

void	draw_graphics(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->height)
		{
			if (map[y][x] == '1')
				draw_instance(data, data->wall, x, y);
			if (map[y][x] == 'C')
				draw_instance(data, data->collectible, x, y);
			if (map[y][x] == 'E')
				draw_instance(data, data->exit_closed, x, y);
			x++;
		}
		y++;
	}
	draw_instance(data, data->player, data->xpos, data->ypos);
}

void	open_window(t_data *data)
{
	data->window = mlx_init(data->width * TILE_SIZE,
			data->height * TILE_SIZE, TITLE, false);
	if (!data->window)
		nuke_everything(data, ERROR_WINDOW);
	load_images(data);
	draw_graphics(data, data->map_array);
}
