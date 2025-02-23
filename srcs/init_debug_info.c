/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_debug_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:37:54 by kamitsui          #+#    #+#             */
/*   Updated: 2024/12/13 21:19:05 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	copy_debug(t_game *game, t_debug debug)
{
	int	i;

	game->debug.game = game;
	game->map.debug = debug;
	game->img_3d.debug = debug;
	game->img_2d.debug = debug;
	game->frame.debug = debug;
	i = 0;
	while (i < 4)
	{
		game->texture[i].debug = game->debug;
		i++;
	}
}

int	init_debug_info(t_game *game)
{
	int	fd;

	if (IS_DEBUG != true)
		fd = STDOUT_FILENO;
	else
	{
		fd = open_log(LOG_FILE, O_TRUNC);
		if (fd == -1)
		{
			printf("Error\n");
			return (EXIT_FAILURE);
		}
	}
	game->debug.fd = fd;
	copy_debug(game, game->debug);
	return (EXIT_SUCCESS);
}
