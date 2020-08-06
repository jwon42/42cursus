/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_yeji_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:34:25 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:20:20 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void			calcul_values(t_draw_yeji *dy, t_game *game)
{
	dy->inv_det = 1.0 / (game->config.player.plane.x * game->config.player.dir.y
		- game->config.player.dir.x * game->config.player.plane.y);
	dy->transform.x = dy->inv_det * (game->config.player.dir.y * dy->yeji.x
		- game->config.player.dir.x * dy->yeji.y);
	dy->transform.y = dy->inv_det * (-game->config.player.plane.y * dy->yeji.x
		+ game->config.player.plane.x * dy->yeji.y);
	dy->yeji_screen_x = (int)((game->config.res[X] / 2) * (1 + dy->transform.x
		/ dy->transform.y));
	dy->yeji_height = abs((int)(game->config.res[Y] / dy->transform.y));
	dy->draw_start.y = -dy->yeji_height / 2 + ((game->config.res[Y] / 2)
		* game->config.player.cam_height);
	if (dy->draw_start.y < 0)
		dy->draw_start.y = 0;
	dy->draw_end.y = dy->yeji_height / 2 + ((game->config.res[Y] / 2)
		* game->config.player.cam_height);
	if (dy->draw_end.y >= game->config.res[Y])
		dy->draw_end.y = game->config.res[Y] - 1;
	dy->yeji_width = abs((int)(game->config.res[Y] / dy->transform.y));
	dy->draw_start.x = -dy->yeji_width / 2 + dy->yeji_screen_x;
	if (dy->draw_start.x < 0)
		dy->draw_start.x = 0;
	dy->draw_end.x = dy->yeji_width / 2 + dy->yeji_screen_x;
	if (dy->draw_end.x >= game->config.res[X])
		dy->draw_end.x = game->config.res[X] - 1;
	dy->stripe = dy->draw_start.x;
}

static void			pix_on_yeji_image(t_draw_yeji *dy, t_game *game)
{
	dy->d = dy->y * game->yeji->size_l - (game->config.res[Y]
		* game->config.player.cam_height)
		* (game->yeji->size_l / 2) + dy->yeji_height
		* game->yeji->size_l / 2;
	dy->tex.y = ((dy->d * game->yeji->height) / dy->yeji_height)
		/ game->yeji->size_l;
	dy->totcolor = game->yeji->data[dy->tex.y
		* game->yeji->size_l + dy->tex.x
		* game->yeji->bpp / 8]
		+ game->yeji->data[dy->tex.y
		* game->yeji->size_l + dy->tex.x
		* game->yeji->bpp / 8 + 1]
		+ game->yeji->data[dy->tex.y
		* game->yeji->size_l + dy->tex.x
		* game->yeji->bpp / 8 + 2];
}

static void			is_black(t_draw_yeji *dy, t_game *game)
{
	game->img->data[dy->y * game->img->size_l
		+ dy->stripe * game->img->bpp / 8] =
		game->yeji->data[dy->tex.y
		* game->yeji->size_l + dy->tex.x
		* game->yeji->bpp / 8];
	game->img->data[dy->y * game->img->size_l
		+ dy->stripe * game->img->bpp / 8 + 1] =
		game->yeji->data[dy->tex.y
		* game->yeji->size_l + dy->tex.x
		* game->yeji->bpp / 8 + 1];
	game->img->data[dy->y * game->img->size_l
		+ dy->stripe * game->img->bpp / 8 + 2] =
		game->yeji->data[dy->tex.y
		* game->yeji->size_l + dy->tex.x
		* game->yeji->bpp / 8 + 2];
}

static void			make_yeji(t_draw_yeji *dy, t_game *game, t_ray *ray)
{
	dy->yeji.x = dy->yejis[dy->i].coord.x - (game->config.player.pos.x - 0.5);
	dy->yeji.y = dy->yejis[dy->i].coord.y - (game->config.player.pos.y - 0.5);
	calcul_values(dy, game);
	while (dy->stripe < dy->draw_end.x)
	{
		dy->tex.x = (int)(game->yeji->size_l * (dy->stripe
		- (-dy->yeji_width / 2 + dy->yeji_screen_x))
			* game->yeji->width / dy->yeji_width)
			/ game->yeji->size_l;
		if (dy->transform.y > 0 && dy->stripe > 0 && dy->stripe
			< game->config.res[X] && dy->transform.y
			< ray->z_buffer[dy->stripe])
		{
			dy->y = dy->draw_start.y;
			while (dy->y < dy->draw_end.y)
			{
				pix_on_yeji_image(dy, game);
				if (dy->totcolor != 0)
					is_black(dy, game);
				dy->y++;
			}
		}
		dy->stripe++;
	}
}

int					draw_yeji(t_ray *ray, t_game *game)
{
	t_draw_yeji *dy;

	if (!(dy = malloc(sizeof(t_draw_yeji))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(dy, sizeof(t_draw_yeji));
	dy->i = 0;
	dy->yejis = list_to_tab_yeji(game);
	sort_yeji(game, dy->yejis,
		ft_lstsize((t_list *)game->yejis));
	while (dy->i < ft_lstsize((t_list *)game->yejis))
	{
		make_yeji(dy, game, ray);
		dy->i++;
	}
	free(dy);
	free(dy->yejis);
	return (1);
}
