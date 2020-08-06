/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:34:40 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 14:19:36 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		set_texture(char *path, int idx, t_game *game)
{
	if (!(game->tex[idx]->img = mlx_xpm_file_to_image(game->mlx, path,
												&game->tex[idx]->width,
												&game->tex[idx]->height)))
		exit_program("No such file(.xpm) or directory");
	game->tex[idx]->data = mlx_get_data_addr(game->tex[idx]->img,
											&game->tex[idx]->bpp,
											&game->tex[idx]->size_l,
											&game->tex[idx]->endian);
}

static void		set_sprite(char *path, t_game *game)
{
	if (!(game->sprite->img = mlx_xpm_file_to_image(game->mlx, path,
											&game->sprite->width,
											&game->sprite->height)))
		exit_program("No such file(.xpm) or directory");
	game->sprite->data = mlx_get_data_addr(game->sprite->img,
											&game->sprite->bpp,
											&game->sprite->size_l,
											&game->sprite->endian);
}

void			convert_xpm_to_img(t_game *game)
{
	set_texture(game->config.texture[0], 0, game);
	set_texture(game->config.texture[1], 1, game);
	set_texture(game->config.texture[2], 2, game);
	set_texture(game->config.texture[3], 3, game);
	set_sprite(game->config.texture[4], game);
}
