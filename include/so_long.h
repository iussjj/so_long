/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:41:11 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/18 20:01:54 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"

# define MAXWIDTH 3840
# define MAXHEIGHT 2160
# define TILE_SIZE 64
# define TITLE "Son moro!"

# define ERROR_FILETYPE "Error: invalid map filetype"
# define ERROR_ARGC "Error: only one map file allowed"
# define ERROR_CHARS "Error: map file contains invalid characters"
# define ERROR_WINDOW "Error: failed to initialize window"
# define ERROR_IMAGE "Error: failed to load images"
# define ERROR_DRAW "Error: failed to display graphics"
# define ERROR_MALLOC "Memory allocation error"

# define WIN_MESSAGE "A winner is you!"
# define EXIT_MESSAGE "So long, and thanks for all the fish!"

typedef struct s_data
{
	mlx_t		*window;
	char		**map_array;
	char		**map_copy;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit_closed;
	mlx_image_t	*exit_open;
	mlx_image_t	*wall;
	mlx_image_t	*bg;
	int			width;
	int			height;
	int			players;
	int			exits;
	int			collectibles;

	//track game state:
	int			xpos;
	int			ypos;
	int			moves;
	int			collected;
}	t_data;

//initialize_data.c
void	init_data(t_data *data, char *mapfile);
bool	valid_file_extension(char *string);
void	read_map_file(t_data *data, char *src);
void	valid_map_chars(t_data *data, char **map);
void	init_map_attributes(t_data *data, char **map);

//validate_map.c
bool	valid_rectangle(char **map);
bool	valid_enclosed(t_data *data, char **map);
bool	valid_objects(t_data *data);
void	flood_fill(int y, int x, char **map);
bool	valid_path(int y, int x, char **map);

//graphics.c
void	load_images(t_data *data);
void	draw_instance(t_data *data, mlx_image_t *asset, int xpos, int ypos);
void	draw_graphics(t_data *data, char **map);
void	open_window(t_data *data);

//user_input.c
void	keypress(mlx_key_data_t pressed_key, void *param);
void	process_move(t_data *data, size_t x_change, size_t y_change);
void	move_player(t_data *data, size_t new_x, size_t new_y);
void	get_collectible(t_data *data, int col_x, int col_y);
void	check_win(t_data *data);

//clean_exit.c
void	*free_and_nullify(void *willy);
void	*free_map_array(char **map);
void	*free_data(t_data *data);
void	end_game(void *param);
void	nuke_everything(t_data *data, char *errmsg);

mlx_image_t	*load_texture(t_data *data, char *filepath);

#endif