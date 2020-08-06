/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:34:25 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:20:18 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void			calcul_values(t_draw_sprite *ds, t_game *game)
{
	ds->inv_det = 1.0 / (game->config.player.plane.x * game->config.player.dir.y
		- game->config.player.dir.x * game->config.player.plane.y);
	ds->transform.x = ds->inv_det * (game->config.player.dir.y * ds->sprite.x
		- game->config.player.dir.x * ds->sprite.y);
	ds->transform.y = ds->inv_det * (-game->config.player.plane.y * ds->sprite.x
		+ game->config.player.plane.x * ds->sprite.y);
	ds->sprite_screen_x = (int)((game->config.res[X] / 2) * (1 + ds->transform.x
		/ ds->transform.y));
	ds->sprite_height = abs((int)(game->config.res[Y] / ds->transform.y));
	ds->draw_start.y = -ds->sprite_height / 2 + ((game->config.res[Y] / 2)
		* game->config.player.cam_height);
	if (ds->draw_start.y < 0)
		ds->draw_start.y = 0;
	ds->draw_end.y = ds->sprite_height / 2 + ((game->config.res[Y] / 2)
		* game->config.player.cam_height);
	if (ds->draw_end.y >= game->config.res[Y])
		ds->draw_end.y = game->config.res[Y] - 1;
	ds->sprite_width = abs((int)(game->config.res[Y] / ds->transform.y));
	ds->draw_start.x = -ds->sprite_width / 2 + ds->sprite_screen_x;
	if (ds->draw_start.x < 0)
		ds->draw_start.x = 0;
	ds->draw_end.x = ds->sprite_width / 2 + ds->sprite_screen_x;
	if (ds->draw_end.x >= game->config.res[X])
		ds->draw_end.x = game->config.res[X] - 1;
	ds->stripe = ds->draw_start.x;
}

static void			pix_on_sprite_image(t_draw_sprite *ds, t_game *game)
{
	ds->d = ds->y * game->sprite->size_l - (game->config.res[Y]
		* game->config.player.cam_height)
		* (game->sprite->size_l / 2) + ds->sprite_height
		* game->sprite->size_l / 2;
	ds->tex.y = ((ds->d * game->sprite->height) / ds->sprite_height)
		/ game->sprite->size_l;
	ds->totcolor = game->sprite->data[ds->tex.y
		* game->sprite->size_l + ds->tex.x
		* game->sprite->bpp / 8]
		+ game->sprite->data[ds->tex.y
		* game->sprite->size_l + ds->tex.x
		* game->sprite->bpp / 8 + 1]
		+ game->sprite->data[ds->tex.y
		* game->sprite->size_l + ds->tex.x
		* game->sprite->bpp / 8 + 2];
}

static void			is_black(t_draw_sprite *ds, t_game *game)
{
	game->img->data[ds->y * game->img->size_l
		+ ds->stripe * game->img->bpp / 8] =
		game->sprite->data[ds->tex.y
		* game->sprite->size_l + ds->tex.x
		* game->sprite->bpp / 8];
	game->img->data[ds->y * game->img->size_l
		+ ds->stripe * game->img->bpp / 8 + 1] =
		game->sprite->data[ds->tex.y
		* game->sprite->size_l + ds->tex.x
		* game->sprite->bpp / 8 + 1];
	game->img->data[ds->y * game->img->size_l
		+ ds->stripe * game->img->bpp / 8 + 2] =
		game->sprite->data[ds->tex.y
		* game->sprite->size_l + ds->tex.x
		* game->sprite->bpp / 8 + 2];
}

static void			make_sprite(t_draw_sprite *ds, t_game *game, t_ray *ray)
{
	ds->sprite.x = ds->sprites[ds->i].coord.x
				- (game->config.player.pos.x - 0.5);
	ds->sprite.y = ds->sprites[ds->i].coord.y
				- (game->config.player.pos.y - 0.5);
	calcul_values(ds, game);
	while (ds->stripe < ds->draw_end.x)
	{
		ds->tex.x = (int)(game->sprite->size_l * (ds->stripe
		- (-ds->sprite_width / 2 + ds->sprite_screen_x))
			* game->sprite->width / ds->sprite_width) / game->sprite->size_l;
		if (ds->transform.y > 0 && ds->stripe > 0 && ds->stripe
			< game->config.res[X] && ds->transform.y
			< ray->z_buffer[ds->stripe])
		{
			ds->y = ds->draw_start.y;
			while (ds->y < ds->draw_end.y)
			{
				pix_on_sprite_image(ds, game);
				if (ds->totcolor != 0)
					is_black(ds, game);
				ds->y++;
			}
		}
		ds->stripe++;
	}
}

int					draw_sprite(t_ray *ray, t_game *game)
{
	t_draw_sprite *ds;

	if (!(ds = malloc(sizeof(t_draw_sprite))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(ds, sizeof(t_draw_sprite));
	ds->i = 0;
	ds->sprites = list_to_tab_sprite(game);
	sort_sprite(game, ds->sprites,
		ft_lstsize((t_list *)game->sprites));
	while (ds->i < ft_lstsize((t_list *)game->sprites))
	{
		make_sprite(ds, game, ray);
		ds->i++;
	}
	free(ds);
	free(ds->sprites);
	return (1);
}
