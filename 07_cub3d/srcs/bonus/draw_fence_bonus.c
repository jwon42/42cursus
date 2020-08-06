/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fence_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:34:25 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:20:15 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void			calcul_values(t_draw_fence *df, t_game *game)
{
	df->inv_det = 1.0 / (game->config.player.plane.x * game->config.player.dir.y
		- game->config.player.dir.x * game->config.player.plane.y);
	df->transform.x = df->inv_det * (game->config.player.dir.y * df->fence.x
		- game->config.player.dir.x * df->fence.y);
	df->transform.y = df->inv_det * (-game->config.player.plane.y * df->fence.x
		+ game->config.player.plane.x * df->fence.y);
	df->fence_screen_x = (int)((game->config.res[X] / 2) * (1 + df->transform.x
		/ df->transform.y));
	df->fence_height = abs((int)(game->config.res[Y] / df->transform.y));
	df->draw_start.y = -df->fence_height / 2 + ((game->config.res[Y] / 2)
		* game->config.player.cam_height);
	if (df->draw_start.y < 0)
		df->draw_start.y = 0;
	df->draw_end.y = df->fence_height / 2 + ((game->config.res[Y] / 2)
		* game->config.player.cam_height);
	if (df->draw_end.y >= game->config.res[Y])
		df->draw_end.y = game->config.res[Y] - 1;
	df->fence_width = abs((int)(game->config.res[Y] / df->transform.y));
	df->draw_start.x = -df->fence_width / 2 + df->fence_screen_x;
	if (df->draw_start.x < 0)
		df->draw_start.x = 0;
	df->draw_end.x = df->fence_width / 2 + df->fence_screen_x;
	if (df->draw_end.x >= game->config.res[X])
		df->draw_end.x = game->config.res[X] - 1;
	df->stripe = df->draw_start.x;
}

static void			pix_on_fence_image(t_draw_fence *df, t_game *game)
{
	df->d = df->y * game->fence->size_l - (game->config.res[Y]
		* game->config.player.cam_height)
		* (game->fence->size_l / 2) + df->fence_height
		* game->fence->size_l / 2;
	df->tex.y = ((df->d * game->fence->height) / df->fence_height)
		/ game->fence->size_l;
	df->totcolor = game->fence->data[df->tex.y
		* game->fence->size_l + df->tex.x
		* game->fence->bpp / 8]
		+ game->fence->data[df->tex.y
		* game->fence->size_l + df->tex.x
		* game->fence->bpp / 8 + 1]
		+ game->fence->data[df->tex.y
		* game->fence->size_l + df->tex.x
		* game->fence->bpp / 8 + 2];
}

static void			is_black(t_draw_fence *df, t_game *game)
{
	game->img->data[df->y * game->img->size_l
		+ df->stripe * game->img->bpp / 8] =
		game->fence->data[df->tex.y
		* game->fence->size_l + df->tex.x
		* game->fence->bpp / 8];
	game->img->data[df->y * game->img->size_l
		+ df->stripe * game->img->bpp / 8 + 1] =
		game->fence->data[df->tex.y
		* game->fence->size_l + df->tex.x
		* game->fence->bpp / 8 + 1];
	game->img->data[df->y * game->img->size_l
		+ df->stripe * game->img->bpp / 8 + 2] =
		game->fence->data[df->tex.y
		* game->fence->size_l + df->tex.x
		* game->fence->bpp / 8 + 2];
}

static void			make_fence(t_draw_fence *df, t_game *game, t_ray *ray)
{
	df->fence.x = df->fences[df->i].coord.x
				- (game->config.player.pos.x - 0.5);
	df->fence.y = df->fences[df->i].coord.y
				- (game->config.player.pos.y - 0.5);
	calcul_values(df, game);
	while (df->stripe < df->draw_end.x)
	{
		df->tex.x = (int)(game->fence->size_l * (df->stripe
		- (-df->fence_width / 2 + df->fence_screen_x))
			* game->fence->width / df->fence_width) / game->fence->size_l;
		if (df->transform.y > 0 && df->stripe > 0 && df->stripe
			< game->config.res[X] && df->transform.y
			< ray->z_buffer[df->stripe])
		{
			df->y = df->draw_start.y;
			while (df->y < df->draw_end.y)
			{
				pix_on_fence_image(df, game);
				if (df->totcolor != 0)
					is_black(df, game);
				df->y++;
			}
		}
		df->stripe++;
	}
}

int					draw_fence(t_ray *ray, t_game *game)
{
	t_draw_fence *df;

	if (!(df = malloc(sizeof(t_draw_fence))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(df, sizeof(t_draw_fence));
	df->i = 0;
	df->fences = list_to_tab_fence(game);
	sort_fence(game, df->fences,
		ft_lstsize((t_list *)game->fences));
	while (df->i < ft_lstsize((t_list *)game->fences))
	{
		make_fence(df, game, ray);
		df->i++;
	}
	free(df);
	free(df->fences);
	return (1);
}
