/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_skybox_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:50:04 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:59:51 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void		draw_box(t_game *game, double x, double y, int color)
{
	int		i;
	int		j;
	int		tile_size;
	int		height;

	tile_size = game->config.res[Y] / 130;
	height = game->config.res[Y] - (game->config.row * tile_size) - 10;
	x *= tile_size;
	y *= tile_size;
	i = 0;
	while (i < tile_size)
	{
		j = 0;
		while (j < tile_size)
		{
			pixel_put_to_image(color, x + j + 10, y + i + height, game->img);
			j++;
		}
		i++;
	}
}

void			draw_boxes(t_game *game, int i, int j)
{
	if (check_valid_chr(game->config.map[i][j]) == 0)
		draw_box(game, j, i, 13158600);
	if (check_valid_chr(game->config.map[i][j]) == 2)
		draw_box(game, j, i, 38580);
	if (check_valid_chr(game->config.map[i][j]) == 3)
		draw_box(game, j, i, 13158600);
	if (check_valid_chr(game->config.map[i][j]) == 5)
		draw_box(game, j, i, 16776960);
	if (check_valid_chr(game->config.map[i][j]) == 6)
		draw_box(game, j, i, 0);
	if (check_valid_chr(game->config.map[i][j]) == 7)
		draw_box(game, j, i, 16711880);
	if (check_valid_chr(game->config.map[i][j]) == 8)
		draw_box(game, j, i, 25750);
}

static void		draw_player(t_game *game, double x, double y, int color)
{
	int		i;
	int		j;
	int		tile_size;
	int		height;

	tile_size = game->config.res[Y] / 130;
	height = game->config.res[Y] - (game->config.row * tile_size) - 11;
	x *= tile_size;
	y *= tile_size;
	i = 0;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			pixel_put_to_image(color, x + j + 9, y + i + height, game->img);
			j++;
		}
		i++;
	}
}

void			view_iteminfo(t_game *game)
{
	char	*value;
	char	*msg;
	int		tile_size;
	int		height;

	tile_size = game->config.res[Y] / 130;
	height = game->config.res[Y] - (game->config.row * tile_size) - 30;
	value = ft_itoa(game->config.coin);
	if (game->config.coin > 0)
	{
		msg = ft_strjoin("NUMBER OF KEYS TO FIND : ", value);
		mlx_string_put(game->mlx, game->win, 20, height, 0xffffff, msg);
	}
	else
	{
		msg = ft_strdup("MISSION COMPLETE :) GO TO THE PRINCESS!!");
		mlx_string_put(game->mlx, game->win, 20, height, 0xffffff, msg);
	}
	free(value);
	free(msg);
}

void			view_skybox(t_game *game)
{
	int		i;
	int		j;
	double	pos_y;
	double	pos_x;

	pos_y = game->config.player.pos.y;
	pos_x = game->config.player.pos.x;
	i = 0;
	while (i < game->config.row)
	{
		j = 0;
		while (j < game->config.col)
		{
			draw_boxes(game, i, j);
			draw_player(game, pos_x, pos_y, 16711680);
			j++;
		}
		i++;
	}
}
