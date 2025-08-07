/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:41:11 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/06 18:27:26 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "MLX42/MLX42.h"

#define MAXWIDTH 3840
#define MAXHEIGHT 2160
#define TILE_SIZE 64
#define TITLE "Looooooooooooooongloooooooong maaaaaaaaaaaaaaaaaaannnn!"

#define ERROR_FILETYPE "Error\nInvalid map filetype\n"
#define ERROR_ARGC "Error\nPlese specify one map file\n"

typedef struct s_data
{
	mlx_t	*window;
	char	**map_array;
	char	**map_copy;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit_closed;
	mlx_image_t	*exit_open;
	mlx_image_t	*wall;
	mlx_image_t	*bg;
	int		width;
	int		height;
	int		players;
	int		exits;
	int		collectibles;
	
	//track game state:
	int		xpos;
	int		ypos;
	int		moves;
	int		collected;
}	t_data;

void	close_game(void *param);

// window_management.c
mlx_image_t	*load_texture(t_data *data, char *filepath);
void		load_images(t_data *data);
void		draw_graphics(t_data *data, char **map);
void		start_game(t_data *data);

// user_input.c
void	keypress(mlx_key_data_t pressed_key, void *param);
void	process_move(t_data *data, size_t x_change, size_t y_change);
void	move_player(t_data *data, size_t new_x, size_t new_y);
void	get_collectible(t_data *data, int col_x, int col_y);
void	check_win(t_data *data);

#endif