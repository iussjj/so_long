/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:26:11 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/18 20:14:02 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keypress(mlx_key_data_t pressed_key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (pressed_key.action == MLX_PRESS || pressed_key.action == MLX_REPEAT)
	{
		if (pressed_key.key == MLX_KEY_W || pressed_key.key == MLX_KEY_UP)
			process_move(data, 0, -1);
		if (pressed_key.key == MLX_KEY_S || pressed_key.key == MLX_KEY_DOWN)
			process_move(data, 0, 1);
		if (pressed_key.key == MLX_KEY_A || pressed_key.key == MLX_KEY_LEFT)
			process_move(data, -1, 0);
		if (pressed_key.key == MLX_KEY_D || pressed_key.key == MLX_KEY_RIGHT)
			process_move(data, 1, 0);
		if (pressed_key.key == MLX_KEY_ESCAPE)
			end_game(param);
	}
}

void	process_move(t_data *data, size_t x_change, size_t y_change)
{
	size_t	new_x;
	size_t	new_y;
	char	moveto;

	new_x = data->xpos + x_change;
	new_y = data->ypos + y_change;
	moveto = data->map_array[new_y][new_x];
	if (moveto == '1')
		return ;
	move_player(data, new_x, new_y);
	if (data->map_array[new_y][new_x] == 'C')
		get_collectible(data, new_x, new_y);
	if (data->map_array[new_y][new_x] == 'E')
		check_win(data);
}

void	move_player(t_data *data, size_t new_x, size_t new_y)
{
	data->xpos = new_x;
	data->ypos = new_y;
	data->player->instances->x = new_x * TILE_SIZE;
	data->player->instances->y = new_y * TILE_SIZE;
	data->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(data->moves, 1);
	ft_putchar_fd('\n', 1);
}

void	get_collectible(t_data *data, int col_x, int col_y)
{
	int	i;

	data->map_array[col_y][col_x] = '0';
	i = 0;
	while (i < data->collectibles)
	{
		if (data->collectible->instances[i].x == col_x * TILE_SIZE
			&& data->collectible->instances[i].y == col_y * TILE_SIZE)
		{
			data->collectible->instances[i].enabled = false;
			break ;
		}
		i++;
	}
	data->collected++;
	if (data->collected == data->collectibles)
	{
		data->exit_closed->instances->enabled = false;
		if (mlx_image_to_window(data->window, data->exit_open,
				data->exit_closed->instances->x,
				data->exit_closed->instances->y) < 0)
			nuke_everything(data, ERROR_DRAW);
		data->player->instances[0].z = data->exit_open->instances[0].z + 1;
	}
}

void	check_win(t_data *data)
{
	if (data->collected == data->collectibles)
	{
		ft_putendl_fd(WIN_MESSAGE, 1);
		end_game(data);
	}
}
