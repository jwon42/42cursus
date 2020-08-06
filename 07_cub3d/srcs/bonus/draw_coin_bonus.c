/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_coin_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:06:36 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:20:12 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void			calcul_values(t_draw_coin *dc, t_game *game)
{
	dc->inv_det = 1.0 / (game->config.player.plane.x * game->config.player.dir.y
		- game->config.player.dir.x * game->config.player.plane.y);
	dc->transform.x = dc->inv_det * (game->config.player.dir.y * dc->coin.x
		- game->config.player.dir.x * dc->coin.y);
	dc->transform.y = dc->inv_det * (-game->config.player.plane.y * dc->coin.x
		+ game->config.player.plane.x * dc->coin.y);
	dc->coin_screen_x = (int)((game->config.res[X] / 2) * (1 + dc->transform.x
		/ dc->transform.y));
	dc->coin_height = abs((int)(game->config.res[Y] / dc->transform.y));
	dc->draw_start.y = -dc->coin_height / 2 + ((game->config.res[Y] / 2)
		* game->config.player.cam_height);
	if (dc->draw_start.y < 0)
		dc->draw_start.y = 0;
	dc->draw_end.y = dc->coin_height / 2 + ((game->config.res[Y] / 2)
		* game->config.player.cam_height);
	if (dc->draw_end.y >= game->config.res[Y])
		dc->draw_end.y = game->config.res[Y] - 1;
	dc->coin_width = abs((int)(game->config.res[Y] / dc->transform.y));
	dc->draw_start.x = -dc->coin_width / 2 + dc->coin_screen_x;
	if (dc->draw_start.x < 0)
		dc->draw_start.x = 0;
	dc->draw_end.x = dc->coin_width / 2 + dc->coin_screen_x;
	if (dc->draw_end.x >= game->config.res[X])
		dc->draw_end.x = game->config.res[X] - 1;
	dc->stripe = dc->draw_start.x;
}

static void			pix_on_coin_image(t_draw_coin *dc, t_game *game)
{
	dc->d = dc->y * game->coin->size_l - (game->config.res[Y]
		* game->config.player.cam_height)
		* (game->coin->size_l / 2) + dc->coin_height
		* game->coin->size_l / 2;
	dc->tex.y = ((dc->d * game->coin->height) / dc->coin_height)
		/ game->coin->size_l;
	dc->totcolor = game->coin->data[dc->tex.y
		* game->coin->size_l + dc->tex.x
		* game->coin->bpp / 8]
		+ game->coin->data[dc->tex.y
		* game->coin->size_l + dc->tex.x
		* game->coin->bpp / 8 + 1]
		+ game->coin->data[dc->tex.y
		* game->coin->size_l + dc->tex.x
		* game->coin->bpp / 8 + 2];
}

static void			is_black(t_draw_coin *dc, t_game *game)
{
	game->img->data[dc->y * game->img->size_l
		+ dc->stripe * game->img->bpp / 8] =
		game->coin->data[dc->tex.y
		* game->coin->size_l + dc->tex.x
		* game->coin->bpp / 8];
	game->img->data[dc->y * game->img->size_l
		+ dc->stripe * game->img->bpp / 8 + 1] =
		game->coin->data[dc->tex.y
		* game->coin->size_l + dc->tex.x
		* game->coin->bpp / 8 + 1];
	game->img->data[dc->y * game->img->size_l
		+ dc->stripe * game->img->bpp / 8 + 2] =
		game->coin->data[dc->tex.y
		* game->coin->size_l + dc->tex.x
		* game->coin->bpp / 8 + 2];
}

static void			make_coin(t_draw_coin *dc, t_game *game, t_ray *ray)
{
	dc->coin.x = dc->coins[dc->i].coord.x - (game->config.player.pos.x - 0.5);
	dc->coin.y = dc->coins[dc->i].coord.y - (game->config.player.pos.y - 0.5);
	calcul_values(dc, game);
	while (dc->stripe < dc->draw_end.x)
	{
		dc->tex.x = (int)(game->coin->size_l * (dc->stripe
		- (-dc->coin_width / 2 + dc->coin_screen_x))
			* game->coin->width / dc->coin_width)
			/ game->coin->size_l;
		if (dc->transform.y > 0 && dc->stripe > 0 && dc->stripe
			< game->config.res[X] && dc->transform.y
			< ray->z_buffer[dc->stripe])
		{
			dc->y = dc->draw_start.y;
			while (dc->y < dc->draw_end.y)
			{
				pix_on_coin_image(dc, game);
				if (dc->totcolor != 0)
					is_black(dc, game);
				dc->y++;
			}
		}
		dc->stripe++;
	}
}

int					draw_coin(t_ray *ray, t_game *game)
{
	t_draw_coin *dc;

	if (!(dc = malloc(sizeof(t_draw_coin))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(dc, sizeof(t_draw_coin));
	dc->i = 0;
	dc->coins = list_to_tab_coin(game);
	sort_coin(game, dc->coins,
		ft_lstsize((t_list *)game->coins));
	while (dc->i < ft_lstsize((t_list *)game->coins))
	{
		make_coin(dc, game, ray);
		dc->i++;
	}
	free(dc);
	free(dc->coins);
	return (1);
}
