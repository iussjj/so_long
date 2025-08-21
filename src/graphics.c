/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:40:37 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/21 17:04:36 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*load_texture(t_data *data, char *filepath)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(filepath);
	if (!texture)
		nuke_everything(data, ERROR_IMAGE);
	image = mlx_texture_to_image(data->window, texture);
	mlx_delete_texture(texture);
	if (!image)
		nuke_everything(data, ERROR_IMAGE);
	return (image);
}

void	load_images(t_data *data)
{
	data->wall = load_texture(data, "./assets/wall.png");
	if (!data->wall)
		nuke_everything(data, ERROR_IMAGE);
	data->player = load_texture(data, "./assets/player.png");
	if (!data->player)
		nuke_everything(data, ERROR_IMAGE);
	data->collectible = load_texture(data, "./assets/collectible.png");
	if (!data->collectible)
		nuke_everything(data, ERROR_IMAGE);
	data->exit_closed = load_texture(data, "./assets/exit_closed.png");
	if (!data->exit_closed)
		nuke_everything(data, ERROR_IMAGE);
	data->exit_open = load_texture(data, "./assets/exit_open.png");
	if (!data->exit_open)
		nuke_everything(data, ERROR_IMAGE);
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
		while (x < data->width)
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
			data->height * TILE_SIZE, TITLE, true);
	if (!data->window)
		nuke_everything(data, ERROR_WINDOW);
	load_images(data);
	draw_graphics(data, data->map_array);
}
