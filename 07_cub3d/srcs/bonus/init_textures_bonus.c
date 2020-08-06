/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:54:44 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:20:30 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void		init_game_textures(t_game *game, int cnt)
{
	int idx;

	idx = 0;
	if (!(game->tex = malloc(sizeof(t_img *) * cnt - 1)))
		exit_program("Memory allocation failed", 0);
	while (idx < cnt)
	{
		if (!(game->tex[idx] = malloc(sizeof(t_img))))
			exit_program("Memory allocation failed", 0);
		ft_bzero(game->tex[idx], sizeof(t_img));
		idx++;
	}
}

void		init_game_sprite(t_game *game)
{
	if (!(game->sprite = malloc(sizeof(t_img))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(game->sprite, sizeof(t_img));
	if (!(game->sprites = malloc(sizeof(t_list))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(game->sprites, sizeof(t_list));
	game->sprites->coord.x = 0;
	game->sprites->coord.y = 0;
}

void		init_game_coin(t_game *game)
{
	if (!(game->coin = malloc(sizeof(t_img))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(game->coin, sizeof(t_img));
	if (!(game->coins = malloc(sizeof(t_list))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(game->coins, sizeof(t_list));
	game->coins->coord.x = 0;
	game->coins->coord.y = 0;
}

void		init_game_fence(t_game *game)
{
	if (!(game->fence = malloc(sizeof(t_img))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(game->fence, sizeof(t_img));
	if (!(game->fences = malloc(sizeof(t_list))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(game->fences, sizeof(t_list));
	game->fences->coord.x = 0;
	game->fences->coord.y = 0;
}

void		init_game_yeji(t_game *game)
{
	if (!(game->yeji = malloc(sizeof(t_img))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(game->yeji, sizeof(t_img));
	if (!(game->yejis = malloc(sizeof(t_list))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(game->yejis, sizeof(t_list));
	game->yejis->coord.x = 0;
	game->yejis->coord.y = 0;
}
