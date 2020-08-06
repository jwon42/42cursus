/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:39:06 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:57:45 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int			check_around_chr(t_game *game, char c)
{
	if ((game->config.map[(int)game->config.player.pos.y - 1]
						[(int)game->config.player.pos.x] == c) ||
		(game->config.map[(int)game->config.player.pos.y + 1]
						[(int)game->config.player.pos.x] == c) ||
		(game->config.map[(int)game->config.player.pos.y]
						[(int)game->config.player.pos.x - 1] == c) ||
		(game->config.map[(int)game->config.player.pos.y]
						[(int)game->config.player.pos.x + 1] == c))
		return (1);
	return (0);
}

void		open_fence(t_game *game)
{
	game->config.map[game->config.fence.y][game->config.fence.x] = '0';
	game->config.fence_cnt--;
	free(game->fence);
	while (game->fences != NULL)
	{
		free(game->fences);
		game->fences = game->fences->next;
	}
	init_game_fence(game);
	convert_xpm_to_img(game);
	play_sound_effect(3);
}

void		check_coin(t_game *game)
{
	if (game->config.map[(int)game->config.player.pos.y]
						[(int)game->config.player.pos.x] == '3')
	{
		game->config.map[(int)game->config.player.pos.y]
						[(int)game->config.player.pos.x] = '0';
		game->config.coin--;
		free(game->coin);
		while (game->coins != NULL)
		{
			free(game->coins);
			game->coins = game->coins->next;
		}
		init_game_coin(game);
		convert_xpm_to_img(game);
		play_sound_effect(2);
	}
}

void		check_warp(t_game *game)
{
	if (game->config.map[(int)game->config.player.pos.y]
						[(int)game->config.player.pos.x] == '6')
	{
		if (((int)game->config.player.pos.y == game->config.warp[0].y) &&
			((int)game->config.player.pos.x == game->config.warp[0].x))
		{
			game->config.player.pos.y = game->config.warp[1].y;
			game->config.player.pos.x = game->config.warp[1].x - 1;
		}
		else
		{
			game->config.player.pos.y = game->config.warp[0].y;
			game->config.player.pos.x = game->config.warp[0].x - 1;
		}
		game->health--;
		play_sound_effect(1);
	}
}
