/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjahkola <jjahkola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:45:59 by jjahkola          #+#    #+#             */
/*   Updated: 2025/08/07 18:07:57 by jjahkola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_putendl_fd("So long, and thanks for all the fish!", 1);
	exit(0);
}
