/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:40:37 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/07 21:49:08 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//write an error function that prints a specified error message -similar to 
//end game but without the standard exit message!

mlx_image_t	*load_texture(t_data *data, char *filepath)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	
	texture = mlx_load_png(filepath);
	image = mlx_texture_to_image(data->window, texture);
	mlx_delete_texture(texture);
	return(image);
}

void	load_images(t_data *data)
{
	data->wall = load_texture(data, "./assets/wall.png");
	data->player = load_texture(data, "./assets/zombie.png");
	data->collectible = load_texture(data, "./assets/brain.png");
	data->exit_closed = load_texture(data, "./assets/exit_closed.png");
	data->exit_open = load_texture(data, "./assets/exit_open.png");
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
				mlx_image_to_window(data->window, data->wall,
				x * TILE_SIZE, y * TILE_SIZE);
			if (map[y][x] == 'C')
				mlx_image_to_window(data->window, data->collectible,
				x * TILE_SIZE, y * TILE_SIZE);
			if (map[y][x] == 'E')
				mlx_image_to_window(data->window, data->exit_closed,
				x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->window, data->player,
					data->xpos * TILE_SIZE, data->ypos * TILE_SIZE);
}

void	open_window(t_data *data)
{
	data->window = mlx_init(data->width * TILE_SIZE,
					data->height * TILE_SIZE, "Loooong *MAAAANNNN!*", false);
	load_images(data);
	draw_graphics(data, data->map_array);
}

/*
handle mlx function failures!
*/