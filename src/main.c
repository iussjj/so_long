/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:27:29 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/18 20:06:30 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*gamedata;

	if (argc != 2)
		return (printf(ERROR_ARGC), EXIT_FAILURE);
	if (!(valid_file_extension(argv[1])))
		return (ft_putendl_fd(ERROR_FILETYPE, 1), EXIT_FAILURE);
	gamedata = calloc(1, sizeof(t_data));
	if (!gamedata)
		return (ft_putendl_fd(ERROR_MALLOC, 1), EXIT_FAILURE);
	init_data(gamedata, argv[1]);
	open_window(gamedata);
	mlx_close_hook(gamedata->window, end_game, gamedata);
	mlx_key_hook(gamedata->window, keypress, gamedata);
	mlx_loop(gamedata->window);
	return (EXIT_SUCCESS);
}
