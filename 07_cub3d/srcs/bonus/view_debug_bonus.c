/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_debug_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:02:13 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:41:24 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void		view_gameinfo(t_game *game)
{
	char	*msg;
	char	*speed;

	msg = ft_strjoin("MAP NAME : ", game->config.map_name);
	mlx_string_put(game->mlx, game->win, 20, 70, 0xffffff, msg);
	free(msg);
	speed = ft_itoa((int)(game->speed_mov * 100) - 10);
	msg = ft_strjoin("GAME SPEED : ", speed);
	free(speed);
	mlx_string_put(game->mlx, game->win, 20, 90, 0xffffff, msg);
	free(msg);
	msg = ft_strdup("CONTROL(SPEED) : [-], [+]");
	mlx_string_put(game->mlx, game->win, 20, 110, 0xffffff, msg);
	free(msg);
	msg = ft_strdup("CONTROL(CAMERA) : [UP], [DOWN], [LEFT], [RIGHT], [F]");
	mlx_string_put(game->mlx, game->win, 20, 130, 0xffffff, msg);
	free(msg);
	msg = ft_strdup("CONTROL(PLAYER) : [W], [S], [A], [D], [Q], [E]");
	mlx_string_put(game->mlx, game->win, 20, 150, 0xffffff, msg);
	free(msg);
	msg = ft_strdup("CONTROL(JAIL OPEN) : [SPACE]");
	mlx_string_put(game->mlx, game->win, 20, 170, 0xffffff, msg);
	free(msg);
}

static void		view_debuginfo_1(t_game *game)
{
	char	*value;
	char	*msg;

	value = ft_itoa((int)(game->config.player.pos.x * 1000000) / 1000000);
	msg = ft_strjoin("PLAYER POSITION (X) : ", value);
	free(value);
	mlx_string_put(game->mlx, game->win, 20, 200, 0xffffff, msg);
	free(msg);
	value = ft_itoa((int)(game->config.player.pos.y * 1000000) / 1000000);
	msg = ft_strjoin("PLAYER POSITION (Y) : ", value);
	free(value);
	mlx_string_put(game->mlx, game->win, 20, 220, 0xffffff, msg);
	free(msg);
}

static void		view_debuginfo_2(t_game *game)
{
	char	*value;
	char	*msg;

	value = ft_itoa((int)(game->config.player.dir.x * 1000000));
	msg = ft_strjoin("DIRECTION (X) : ", value);
	free(value);
	mlx_string_put(game->mlx, game->win, 20, 250, 0xffffff, msg);
	free(msg);
	value = ft_itoa((int)(game->config.player.dir.y * 1000000));
	msg = ft_strjoin("DIRECTION (Y) : ", value);
	free(value);
	mlx_string_put(game->mlx, game->win, 20, 270, 0xffffff, msg);
	free(msg);
	value = ft_itoa((int)(game->config.player.plane.x * 1000000));
	msg = ft_strjoin("CAMERA PLANE (X) : ", value);
	free(value);
	mlx_string_put(game->mlx, game->win, 20, 290, 0xffffff, msg);
	free(msg);
	value = ft_itoa((int)(game->config.player.plane.y * 1000000));
	msg = ft_strjoin("CAMERA PLANE (Y) : ", value);
	free(value);
	mlx_string_put(game->mlx, game->win, 20, 310, 0xffffff, msg);
	free(msg);
}

void			view_debug(t_game *game)
{
	view_gameinfo(game);
	view_debuginfo_1(game);
	view_debuginfo_2(game);
}
