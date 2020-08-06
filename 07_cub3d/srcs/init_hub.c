/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:56:58 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 14:15:11 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		init_game_speed(t_game *game)
{
	game->debug = 0;
	game->speed_mov = 0.1;
	game->speed_rot = 0.1;
}

static void		init_game_key(t_game *game)
{
	if (!(game->key = malloc(sizeof(t_key))))
		exit_program("Memory allocation failed");
	ft_bzero(game->key, sizeof(t_key));
	game->key->go = 0;
	game->key->back = 0;
	game->key->left = 0;
	game->key->right = 0;
	game->key->go_left = 0;
	game->key->go_right = 0;
	game->key->turn = 0;
	game->key->cam_up = 0;
	game->key->cam_down = 0;
	game->key->rotate_left = 0;
	game->key->rotate_right = 0;
	game->key->speed_down = 0;
	game->key->speed_up = 0;
}

static void		init_game_textures(t_game *game, int cnt)
{
	int idx;

	idx = 0;
	if (!(game->tex = malloc(sizeof(t_img *) * cnt - 1)))
		exit_program("Memory allocation failed");
	while (idx < cnt)
	{
		if (!(game->tex[idx] = malloc(sizeof(t_img))))
			exit_program("Memory allocation failed");
		ft_bzero(game->tex[idx], sizeof(t_img));
		idx++;
	}
}

static void		init_game_sprite(t_game *game)
{
	if (!(game->sprite = malloc(sizeof(t_img))))
		exit_program("Memory allocation failed");
	ft_bzero(game->sprite, sizeof(t_img));
	if (!(game->sprites_on_screen = malloc(sizeof(t_list))))
		exit_program("Memory allocation failed");
	ft_bzero(game->sprites_on_screen, sizeof(t_list));
	game->sprites_on_screen->coord.x = 0;
	game->sprites_on_screen->coord.y = 0;
}

void			init_hub(t_game *game)
{
	init_game_speed(game);
	init_game_key(game);
	init_game_textures(game, 5);
	init_game_sprite(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
				game->config.res[X], game->config.res[Y], "cub3D");
	game->img = new_image(game, game->config.res[X], game->config.res[Y]);
	convert_xpm_to_img(game);
}
