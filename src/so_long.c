/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:27:29 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/06 18:26:10 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
bool	load_textures(t_game game)
{
	mlx_texture_t	player;
	
	//player = mlx_load_png();
}
*/

bool	ber_check(char *string)
{
	int	last_index;
	
	if (ft_strlen(string) < 5)
		return (false);
	last_index = ft_strlen(string) - 1;
	if (string[last_index] == 'r' && string[last_index - 1] == 'e'
	&& string[last_index - 2] == 'b' && string[last_index - 3] == '.')
		return (true);
	else
		return (false);	
}

char	*read_map_file(char *src)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*output;
	size_t	src_fd;
	size_t	bytes_read;

	src_fd = open(src, O_RDONLY);
	bytes_read = read(src_fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	close(src_fd);
	output = ft_strdup(buffer);
	return (output);
}

void	init_map_dimensions(t_data *data, char **map)
{
	int	i;

	i = 0;
	data->width = ft_strlen(map[0]);
	while (map[i])
		i++;
	data->height = i;
	printf("Width: %d\nHeight: %d\n", data->width, data->height);
}

void	init_objects(t_data *data, char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j] != '\0')
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
	printf("Players: %d\nExits: %d\nCollectibles: %d\n", data->players, data->exits, data->collectibles);
	printf("Player position: x %d y %d\n", data->xpos, data->ypos);
}

bool	valid_map_chars(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j] != '\0')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
			&& map[i][j] != 'E' && map[i][j] != 'C')
				return (ft_putendl_fd("Error, invalid map characters!", 1), false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	valid_rectangle(char **map)
{
	int	i;
	size_t	firstline;

	i = 1;
	firstline = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != firstline)
			return (ft_putendl_fd("Error, map not rectangular!", 1), false);
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
				return (ft_putendl_fd("Error, map not enclosed!", 1), false);
			if ((j == 0 || j == data->width - 1) && map[i][j] != '1')
				return (ft_putendl_fd("Error, map not enclosed!", 1), false);
			j++;
		}
		i++;
	}
	return (ft_putendl_fd("Map is enclosed!", 1), true);
}

bool	valid_objects(t_data *data)
{
	if (data->players != 1)
		return (ft_putendl_fd("Error, invalid player count!", 1), false);
	if (data->exits != 1)
		return (ft_putendl_fd("Error, invalid exit count!", 1), false);
	if (data->collectibles == 0)
		return (ft_putendl_fd("Error, invalid collectible count!", 1), false);
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

void	output_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
}

bool	valid_path(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'C'))
			return (ft_putendl_fd("Error, invalid path!", 1), false);
		if (ft_strchr(map[i], 'E'))
			return (ft_putendl_fd("Error, invalid path!", 1), false);
		i++;
	}
	return (true);
}

void	init_data(t_data *data, char *mapfile)
{
	//function to initialize mlx variable
	data->map_array = ft_split(read_map_file(mapfile), '\n');
	data->map_copy = ft_split(read_map_file(mapfile), '\n');
	valid_map_chars(data->map_array);
	init_map_dimensions(data, data->map_array);
	valid_rectangle(data->map_array);
	valid_enclosed(data, data->map_array);
	init_objects(data, data->map_array);
	valid_objects(data);
	flood_fill(data->ypos, data->xpos, data->map_copy);
	output_map(data->map_copy);
	valid_path(data->map_copy);
//	init_textures(data);
	
}

void	close_game(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_putendl_fd("So long, and thanks for all the fish!", 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	*gamedata;

	if (argc != 2)
		return (printf(ERROR_ARGC), 1);
	if (!(ber_check(argv[1])))
		return (printf(ERROR_FILETYPE), 1);
	gamedata = calloc(1, sizeof(t_data));
	init_data(gamedata, argv[1]);
	start_game(gamedata);
	mlx_close_hook(gamedata->window, close_game, gamedata);
	mlx_key_hook(gamedata->window, keypress, gamedata);
	mlx_loop(gamedata->window);
	//mapstring = read_map_file(argv[1]);
	//maparray = ft_split(mapstring, '\n');
	//ft_putendl_fd(maparray[0], 1);
	//ft_putendl_fd(maparray[1], 1);
	//ft_putendl_fd(maparray[2], 1);
	//printf("%zu", ft_strlen(maparray[0]));
	//free(gamedata);
	return(0);
}