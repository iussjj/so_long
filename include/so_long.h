/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:41:11 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/22 15:35:08 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "MLX42/MLX42.h"

# define TILE_SIZE 64
# define TITLE "So long!"

# define ERROR_FILETYPE "Error\nInvalid map filetype"
# define ERROR_OPEN "Error\nCould not open map file, or it does not exist"
# define ERROR_READ "Error\nCould not read map file"
# define ERROR_BIGMAP "Error\nMap file too large"
# define ERROR_EMPTY "Error\nEmpty map file"
# define ERROR_ARGC "Error\nPlease input one map file"
# define ERROR_CHARS "Error\nMap file contains invalid characters"
# define ERROR_WINDOW "Error\nFailed to initialize window"
# define ERROR_IMAGE "Error\nFailed to load images"
# define ERROR_DRAW "Error\nFailed to display graphics"
# define ERROR_MALLOC "Error\nMemory allocation failed"
# define ERROR_CONT "Error\nMap not contiguous"
# define ERROR_RECT "Error\nMap not rectangular"
# define ERROR_ENCLOSED "Error\nMap not enclosed"
# define ERROR_OBJ "Error\nMap must have 1 player, 1 exit and >= 1 collectible"
# define ERROR_PATH "Error\nNo possible path on map"

# define WARNING_BIGMAP "Warning\nMap size should be max 60 X 32"

# define WIN_MESSAGE "A winner is you!"
# define EXIT_MESSAGE "So long, and thanks for all the fish!"

typedef struct s_data
{
	mlx_t		*window;
	char		*source_string;
	char		**map_array;
	char		**map_copy;
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	mlx_image_t	*exit_closed;
	mlx_image_t	*exit_open;
	mlx_image_t	*wall;
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

//main.c
bool		valid_file_extension(char *string);
char		*read_map_file(t_data *data, char *src);

//initialize_data.c
void		init_data(t_data *data);
void		init_map_attributes(t_data *data, char **map);
bool		valid_map_chars(char *map);
bool		map_contiguous(char *map);

//validate_map.c
bool		valid_rect(char **map);
bool		valid_enclosed(t_data *data, char **map);
bool		valid_objects(t_data *data);
void		flood_fill(int y, int x, char **map);
bool		valid_path(int y, int x, char **map);

//graphics.c
mlx_image_t	*load_texture(t_data *data, char *filepath);
void		load_images(t_data *data);
void		draw_instance(t_data *data, mlx_image_t *asset, int xpos, int ypos);
void		draw_graphics(t_data *data, char **map);
void		open_window(t_data *data);

//user_input.c
void		keypress(mlx_key_data_t pressed_key, void *param);
void		process_move(t_data *data, size_t x_change, size_t y_change);
void		move_player(t_data *data, size_t new_x, size_t new_y);
void		get_collectible(t_data *data, int col_x, int col_y);
void		check_win(t_data *data);

//clean_exit.c
void		*free_and_nullify(void *willy);
void		*free_map_array(char **map);
void		*free_data(t_data *data);
void		end_game(void *param);
void		nuke_everything(t_data *data, char *errmsg);

#endif