/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:37:06 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:58:13 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static int		main_loop(void *parameter)
{
	t_game *game;

	game = (t_game *)parameter;
	if (!(raycasting(game)))
		exit(EXIT_FAILURE);
	key_manager(game);
	if (game->config.flag[1])
		view_debug(game);
	view_lifebar(game);
	view_iteminfo(game);
	if (game->health == 0)
		exit_program("GAME OVER", 1);
	return (1);
}

static void		mlx_hub(t_game *game)
{
	mlx_hook(game->win, MLX_KEY_PRESS, 0, (int (*)())key_pressed, game);
	mlx_hook(game->win, MLX_KEY_RELEASE, 0, (int (*)())key_released, game);
	mlx_hook(game->win, MLX_KEY_EXIT, 0, (int (*)())exit_window, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}

int				main(int argc, char *argv[])
{
	t_game		*game;

	if (!(game = (t_game *)malloc(sizeof(t_game))))
		exit_program("Memory allocation failed", 0);
	parse_hub(argc, argv, game);
	init_hub(game);
	play_bgm();
	mlx_hub(game);
	return (EXIT_SUCCESS);
}
