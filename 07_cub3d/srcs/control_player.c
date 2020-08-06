/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:16:55 by jwon              #+#    #+#             */
/*   Updated: 2020/07/29 19:36:50 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		move_go(t_game *game)
{
	if ((check_valid_chr(game->config.map[(int)game->config.player.pos.y]
		[(int)(game->config.player.pos.x + game->config.player.dir.x
		* game->speed_mov)]) == 0) ||
		(check_valid_chr(game->config.map[(int)game->config.player.pos.y]
		[(int)(game->config.player.pos.x + game->config.player.dir.x
		* game->speed_mov)]) == 3))
		game->config.player.pos.x += game->config.player.dir.x
		* game->speed_mov;
	if ((check_valid_chr(game->config.map[(int)(game->config.player.pos.y
		+ game->config.player.dir.y * game->speed_mov)]
		[(int)game->config.player.pos.x]) == 0) ||
		(check_valid_chr(game->config.map[(int)(game->config.player.pos.y
		+ game->config.player.dir.y * game->speed_mov)]
		[(int)game->config.player.pos.x]) == 3))
		game->config.player.pos.y += game->config.player.dir.y
		* game->speed_mov;
}

void		move_back(t_game *game)
{
	if ((check_valid_chr(game->config.map[(int)game->config.player.pos.y]
		[(int)(game->config.player.pos.x - game->config.player.dir.x
		* game->speed_mov)]) == 0) ||
		(check_valid_chr(game->config.map[(int)game->config.player.pos.y]
		[(int)(game->config.player.pos.x - game->config.player.dir.x
		* game->speed_mov)]) == 3))
		game->config.player.pos.x -= game->config.player.dir.x
		* game->speed_mov;
	if ((check_valid_chr(game->config.map[(int)(game->config.player.pos.y
		- game->config.player.dir.y * game->speed_mov)]
		[(int)game->config.player.pos.x]) == 0) ||
		(check_valid_chr(game->config.map[(int)(game->config.player.pos.y
		- game->config.player.dir.y * game->speed_mov)]
		[(int)game->config.player.pos.x]) == 3))
		game->config.player.pos.y -= game->config.player.dir.y
		* game->speed_mov;
}

void		move_left(t_game *game)
{
	if ((check_valid_chr(game->config.map[(int)game->config.player.pos.y]
		[(int)(game->config.player.pos.x - game->config.player.plane.x
		* game->speed_mov)]) == 0) ||
		(check_valid_chr(game->config.map[(int)game->config.player.pos.y]
		[(int)(game->config.player.pos.x - game->config.player.plane.x
		* game->speed_mov)]) == 3))
		game->config.player.pos.x -= game->config.player.plane.x
		* game->speed_mov;
	if ((check_valid_chr(game->config.map[(int)(game->config.player.pos.y
		- game->config.player.plane.y * game->speed_mov)]
		[(int)game->config.player.pos.x]) == 0) ||
		(check_valid_chr(game->config.map[(int)(game->config.player.pos.y
		- game->config.player.plane.y * game->speed_mov)]
		[(int)game->config.player.pos.x]) == 3))
		game->config.player.pos.y -= game->config.player.plane.y
		* game->speed_mov;
}

void		move_right(t_game *game)
{
	if ((check_valid_chr(game->config.map[(int)game->config.player.pos.y]
		[(int)(game->config.player.pos.x + game->config.player.plane.x
		* game->speed_mov)]) == 0) ||
		(check_valid_chr(game->config.map[(int)game->config.player.pos.y]
		[(int)(game->config.player.pos.x + game->config.player.plane.x
		* game->speed_mov)]) == 3))
		game->config.player.pos.x += game->config.player.plane.x
		* game->speed_mov;
	if ((check_valid_chr(game->config.map[(int)(game->config.player.pos.y
		+ game->config.player.plane.y * game->speed_mov)]
		[(int)game->config.player.pos.x]) == 0) ||
		(check_valid_chr(game->config.map[(int)(game->config.player.pos.y
		+ game->config.player.plane.y * game->speed_mov)]
		[(int)game->config.player.pos.x]) == 3))
		game->config.player.pos.y += game->config.player.plane.y
		* game->speed_mov;
}
