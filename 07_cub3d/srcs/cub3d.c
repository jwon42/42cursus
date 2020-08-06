/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:37:06 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 18:06:07 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		main_loop(void *parameter)
{
	t_game *game;

	game = (t_game *)parameter;
	if (!(raycasting(game)))
		exit(EXIT_FAILURE);
	key_manager(game);
	if (game->config.flag[1])
		view_debug(game);
	return (1);
}

static void		mlx_hub(t_game *game)
{
	mlx_hook(game->win, MLX_KEY_PRESS, 0, key_pressed, game);
	mlx_hook(game->win, MLX_KEY_RELEASE, 0, key_released, game);
	mlx_hook(game->win, MLX_KEY_EXIT, 0, exit_window, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}

int				main(int argc, char *argv[])
{
	t_game		*game;

	if (!(game = (t_game *)malloc(sizeof(t_game))))
		exit_program("Memory allocation failed");
	parse_hub(argc, argv, game);
	init_hub(game);
	mlx_hub(game);
	return (EXIT_SUCCESS);
}
