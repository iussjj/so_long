/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:27:29 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/20 20:19:00 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	valid_file_extension(char *string)
{
	int	last_index;

	if (ft_strlen(string) < 4)
		return (false);
	last_index = ft_strlen(string) - 1;
	if (string[last_index] == 'r' && string[last_index - 1] == 'e'
		&& string[last_index - 2] == 'b' && string[last_index - 3] == '.')
		return (true);
	else
		return (false);
}

char	*read_map_file(t_data *data, char *src)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*output;
	ssize_t	src_fd;
	ssize_t	bytes_read;

	src_fd = open(src, O_RDONLY);
	if (src_fd == -1)
		nuke_everything(data, ERROR_OPEN);
	bytes_read = read(src_fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		nuke_everything(data, ERROR_READ);
	if (bytes_read == 0)
		nuke_everything(data, ERROR_EMPTY);
	buffer[bytes_read] = '\0';
	close(src_fd);
	output = ft_strdup(buffer);
	if (!output)
		nuke_everything(data, ERROR_MALLOC);
	return (output);
}

int	main(int argc, char **argv)
{
	t_data	*gamedata;

	if (argc != 2)
		return (ft_putendl_fd(ERROR_ARGC, 2), EXIT_FAILURE);
	if (!(valid_file_extension(argv[1])))
		return (ft_putendl_fd(ERROR_FILETYPE, 2), EXIT_FAILURE);
	gamedata = calloc(1, sizeof(t_data));
	if (!gamedata)
		return (ft_putendl_fd(ERROR_MALLOC, 2), EXIT_FAILURE);
	gamedata->source_string = read_map_file(gamedata, argv[1]);
	if (!gamedata->source_string)
		nuke_everything(gamedata, ERROR_MALLOC);
	init_data(gamedata);
	open_window(gamedata);
	mlx_close_hook(gamedata->window, end_game, gamedata);
	mlx_key_hook(gamedata->window, keypress, gamedata);
	mlx_loop(gamedata->window);
	return (EXIT_SUCCESS);
}
