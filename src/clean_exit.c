/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:45:59 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/08 12:01:39 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_and_nullify(void *willy)
{
	if (willy)
		free (willy);
	willy = NULL;
	return (willy);
}

void	*free_map_array(char **map)
{
	int	i;

	if (map)
	{
			i = 0;
			while (map[i])
			{
				map[i] = free_and_nullify(map[i]);
				i++;
			}
		map = free_and_nullify(map);
	}
	return (NULL);
}

void	*free_data(t_data *data)
{
	if (!data)
		return (NULL);
	if (data->map_array)
		data->map_array = free_map_array(data->map_array);
	if (data->map_copy)
		data->map_copy = free_map_array(data->map_copy);
	if (data->player)
		mlx_delete_image(data->window, data->player);
	if (data->collectible)
		mlx_delete_image(data->window, data->collectible);
	if (data->exit_closed)
		mlx_delete_image(data->window, data->exit_closed);
	if (data->exit_open)
		mlx_delete_image(data->window, data->exit_open);
	if (data->wall)
		mlx_delete_image(data->window, data->wall);
	if (data->bg)
		mlx_delete_image(data->window, data->bg);
	if (data->window)
		mlx_terminate(data->window);
	free (data);
	return (NULL);
}

void	end_game(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data = free_data(data);
	
	ft_printf("So long, and thanks for all the fish!");
	//ft_putendl_fd("So long, and thanks for all the fish!", 1);
	exit(1);
}
