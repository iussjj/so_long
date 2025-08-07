/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:27:29 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/07 18:08:17 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*gamedata;

	if (argc != 2)
		return (printf(ERROR_ARGC), 1);
	if (!(valid_file_extension(argv[1])))
		return (printf(ERROR_FILETYPE), 1);
	gamedata = calloc(1, sizeof(t_data));
	init_data(gamedata, argv[1]);
	open_window(gamedata);
	mlx_close_hook(gamedata->window, close_game, gamedata);
	mlx_key_hook(gamedata->window, keypress, gamedata);
	mlx_loop(gamedata->window);
	return(0);
}
