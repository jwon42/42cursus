/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_key_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:38:34 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:20:03 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void		key_released(int key, void *parameter)
{
	t_game	*game;

	game = (t_game *)parameter;
	(key == KEY_W && game->key->go == 1) ? game->key->go = 0 : 0;
	(key == KEY_S && game->key->back == 1) ? game->key->back = 0 : 0;
	(key == KEY_A && game->key->left == 1) ? game->key->left = 0 : 0;
	(key == KEY_D && game->key->right == 1) ? game->key->right = 0 : 0;
	(key == KEY_Q && game->key->go_left == 1) ? game->key->go_left = 0 : 0;
	(key == KEY_E && game->key->go_right == 1) ? game->key->go_right = 0 : 0;
	(key == KEY_UP && game->key->cam_up == 1) ? game->key->cam_up = 0 : 0;
	(key == KEY_DOWN && game->key->cam_down == 1) ?
											game->key->cam_down = 0 : 0;
	(key == KEY_LEFT && game->key->rotate_left == 1) ?
											game->key->rotate_left = 0 : 0;
	(key == KEY_RIGHT && game->key->rotate_right == 1) ?
											game->key->rotate_right = 0 : 0;
	(key == KEY_PLUS && game->key->speed_up == 1) ?
											game->key->speed_up = 0 : 0;
	(key == KEY_MINUS && game->key->speed_down == 1) ?
											game->key->speed_down = 0 : 0;
	(key == KEY_TAB) ? game->debug = 0 : 0;
}

void		key_pressed(int key, void *parameter)
{
	t_game	*game;

	game = (t_game *)parameter;
	(key == KEY_ESC) ? exit_program("The game was forced to shutdown", 1) : 0;
	(key == KEY_W && game->key->go == 0) ? game->key->go = 1 : 0;
	(key == KEY_S && game->key->back == 0) ? game->key->back = 1 : 0;
	(key == KEY_A && game->key->left == 0) ? game->key->left = 1 : 0;
	(key == KEY_D && game->key->right == 0) ? game->key->right = 1 : 0;
	(key == KEY_Q && game->key->go_left == 0) ? game->key->go_left = 1 : 0;
	(key == KEY_E && game->key->go_right == 0) ? game->key->go_right = 1 : 0;
	(key == KEY_F && game->key->turn == 0) ? turn_around(game) : 0;
	(key == KEY_UP && game->key->cam_up == 0) ? game->key->cam_up = 1 : 0;
	(key == KEY_DOWN && game->key->cam_down == 0) ?
											game->key->cam_down = 1 : 0;
	(key == KEY_LEFT && game->key->rotate_left == 0) ?
											game->key->rotate_left = 1 : 0;
	(key == KEY_RIGHT && game->key->rotate_right == 0) ?
											game->key->rotate_right = 1 : 0;
	(key == KEY_PLUS && game->key->speed_up == 0) ?
											game->key->speed_up = 1 : 0;
	(key == KEY_MINUS && game->key->speed_down == 0) ?
											game->key->speed_down = 1 : 0;
	(key == KEY_TAB) ? game->debug = 1 : 0;
	(key == KEY_SPACE && game->config.fence_cnt > 0 && game->config.coin == 0
						&& check_around_chr(game, '4')) ? open_fence(game) : 0;
}

int			key_manager(t_game *game)
{
	(game->key->go == 1) ? move_go(game) : 0;
	(game->key->back == 1) ? move_back(game) : 0;
	(game->key->left == 1) ? move_left(game) : 0;
	(game->key->right == 1) ? move_right(game) : 0;
	(game->key->cam_up == 1) ? camera_up(game) : 0;
	(game->key->cam_down == 1) ? camera_down(game) : 0;
	(game->key->rotate_left == 1) ? rotate_left(game) : 0;
	(game->key->rotate_right == 1) ? rotate_right(game) : 0;
	(game->key->speed_up == 1) ? game_speed_up(game) : 0;
	(game->key->speed_down == 1) ? game_speed_down(game) : 0;
	(game->debug == 1) ? view_debug(game) : 0;
	if (game->key->go_left == 1)
	{
		move_go(game);
		move_left(game);
	}
	if (game->key->go_right == 1)
	{
		move_go(game);
		move_right(game);
	}
	return (1);
}

void		exit_window(void *parameter)
{
	t_game *game;

	game = (t_game *)parameter;
	exit_program("The game was forced to shutdown", 1);
}
