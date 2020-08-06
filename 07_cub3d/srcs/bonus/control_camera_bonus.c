/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_camera_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:16:57 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:20:05 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void			rotate_left(t_game *game)
{
	double		pre_dir_x;
	double		pre_plane_x;

	pre_dir_x = game->config.player.dir.x;
	pre_plane_x = game->config.player.plane.x;
	game->config.player.dir.x =
				game->config.player.dir.x * cos(-game->speed_rot)
				- game->config.player.dir.y * sin(-game->speed_rot);
	game->config.player.dir.y =
				pre_dir_x * sin(-game->speed_rot)
				+ game->config.player.dir.y * cos(-game->speed_rot);
	game->config.player.plane.x =
				game->config.player.plane.x * cos(-game->speed_rot)
				- game->config.player.plane.y * sin(-game->speed_rot);
	game->config.player.plane.y =
				pre_plane_x * sin(-game->speed_rot)
				+ game->config.player.plane.y * cos(-game->speed_rot);
}

void			rotate_right(t_game *game)
{
	double		pre_dir_x;
	double		pre_plane_x;

	pre_dir_x = game->config.player.dir.x;
	pre_plane_x = game->config.player.plane.x;
	game->config.player.dir.x =
				game->config.player.dir.x * cos(game->speed_rot)
				- game->config.player.dir.y * sin(game->speed_rot);
	game->config.player.dir.y =
				pre_dir_x * sin(game->speed_rot)
				+ game->config.player.dir.y * cos(game->speed_rot);
	game->config.player.plane.x =
				game->config.player.plane.x * cos(game->speed_rot)
				- game->config.player.plane.y * sin(game->speed_rot);
	game->config.player.plane.y =
				pre_plane_x * sin(game->speed_rot)
				+ game->config.player.plane.y * cos(game->speed_rot);
}

void			turn_around(t_game *game)
{
	double		pre_dir_x;
	double		pre_plane_x;

	pre_dir_x = game->config.player.dir.x;
	pre_plane_x = game->config.player.plane.x;
	game->config.player.dir.x =
				game->config.player.dir.x * cos(M_PI)
				- game->config.player.dir.y * sin(M_PI);
	game->config.player.dir.y =
				pre_dir_x * sin(M_PI)
				+ game->config.player.dir.y * cos(M_PI);
	game->config.player.plane.x =
				game->config.player.plane.x * cos(M_PI)
				- game->config.player.plane.y * sin(M_PI);
	game->config.player.plane.y =
				pre_plane_x * sin(M_PI)
				+ game->config.player.plane.y * cos(M_PI);
}

void			camera_up(t_game *game)
{
	if (game->config.player.cam_height < 1.8)
		game->config.player.cam_height += 0.1;
}

void			camera_down(t_game *game)
{
	if (game->config.player.cam_height > 0.2)
		game->config.player.cam_height -= 0.1;
}
