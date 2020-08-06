/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:02:13 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 14:33:20 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		view_gameinfo(t_game *game)
{
	char	*msg;
	char	*speed;

	msg = ft_strjoin("MAP_NAME : ", game->config.map_name);
	mlx_string_put(game->mlx, game->win, 30, 30, 0xb3b3b3, msg);
	free(msg);
	speed = ft_itoa((int)(game->speed_mov * 100) - 10);
	msg = ft_strjoin("GAME SPEED : ", speed);
	free(speed);
	mlx_string_put(game->mlx, game->win, 30, 50, 0xb3b3b3, msg);
	free(msg);
	msg = ft_strdup("CONTROL(SPEED) : [-], [+]");
	mlx_string_put(game->mlx, game->win, 30, 70, 0xb3b3b3, msg);
	free(msg);
	msg = ft_strdup("CONTROL(CAMERA) : [UP], [DOWN], [LEFT], [RIGHT], [F]");
	mlx_string_put(game->mlx, game->win, 30, 90, 0xb3b3b3, msg);
	free(msg);
	msg = ft_strdup("CONTROL(PLAYER) : [W], [S], [A], [D], [Q], [E]");
	mlx_string_put(game->mlx, game->win, 30, 110, 0xb3b3b3, msg);
	free(msg);
}

static void		view_debuginfo_1(t_game *game)
{
	char	*value;
	char	*msg;

	value = ft_itoa((int)(game->config.player.pos.x * 1000000) / 1000000);
	msg = ft_strjoin("PLAYER POSITION (X) : ", value);
	free(value);
	mlx_string_put(game->mlx, game->win, 30, 140, 0xb3b3b3, msg);
	free(msg);
	value = ft_itoa((int)(game->config.player.pos.y * 1000000) / 1000000);
	msg = ft_strjoin("PLAYER POSITION (Y) : ", value);
	free(value);
	mlx_string_put(game->mlx, game->win, 30, 160, 0xb3b3b3, msg);
	free(msg);
}

void			view_debuginfo_2(t_game *game)
{
	char	*value;
	char	*msg;

	value = ft_itoa((int)(game->config.player.dir.x * 1000000));
	msg = ft_strjoin("DIRECTION (X) : ", value);
	free(value);
	mlx_string_put(game->mlx, game->win, 30, 180, 0xb3b3b3, msg);
	free(msg);
	value = ft_itoa((int)(game->config.player.dir.y * 1000000));
	msg = ft_strjoin("DIRECTION (Y) : ", value);
	free(value);
	mlx_string_put(game->mlx, game->win, 30, 200, 0xb3b3b3, msg);
	free(msg);
	value = ft_itoa((int)(game->config.player.plane.x * 1000000));
	msg = ft_strjoin("CAMERA PLANE (X) : ", value);
	free(value);
	mlx_string_put(game->mlx, game->win, 30, 220, 0xb3b3b3, msg);
	free(msg);
	value = ft_itoa((int)(game->config.player.plane.y * 1000000));
	msg = ft_strjoin("CAMERA PLANE (Y) : ", value);
	free(value);
	mlx_string_put(game->mlx, game->win, 30, 240, 0xb3b3b3, msg);
	free(msg);
}

void			view_debug(t_game *game)
{
	view_gameinfo(game);
	view_debuginfo_1(game);
	view_debuginfo_2(game);
}
