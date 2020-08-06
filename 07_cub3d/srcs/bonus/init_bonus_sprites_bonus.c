/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus_sprites_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:01:50 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:20:26 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void		set_coin(char *path, t_game *game)
{
	if (!(game->coin->img = mlx_xpm_file_to_image(game->mlx, path,
											&game->coin->width,
											&game->coin->height)))
		exit_program("No such file(.xpm) or directory", 0);
	game->coin->data = mlx_get_data_addr(game->coin->img,
											&game->coin->bpp,
											&game->coin->size_l,
											&game->coin->endian);
}

void		set_fence(char *path, t_game *game)
{
	if (!(game->fence->img = mlx_xpm_file_to_image(game->mlx, path,
											&game->fence->width,
											&game->fence->height)))
		exit_program("No such file(.xpm) or directory", 0);
	game->fence->data = mlx_get_data_addr(game->fence->img,
											&game->fence->bpp,
											&game->fence->size_l,
											&game->fence->endian);
}

void		set_yeji(char *path, t_game *game)
{
	if (!(game->yeji->img = mlx_xpm_file_to_image(game->mlx, path,
											&game->yeji->width,
											&game->yeji->height)))
		exit_program("No such file(.xpm) or directory", 0);
	game->yeji->data = mlx_get_data_addr(game->yeji->img,
											&game->yeji->bpp,
											&game->yeji->size_l,
											&game->yeji->endian);
}
