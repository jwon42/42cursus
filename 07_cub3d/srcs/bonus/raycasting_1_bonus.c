/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 11:50:48 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:32:29 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void		next_step(t_ray *ray, t_player *player)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->map.x)
						* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - player->pos.x)
						* ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->map.y)
						* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - player->pos.y)
						* ray->delta_dist.y;
	}
}

static void		init_ray(t_ray *ray, t_player *player, t_game *game)
{
	ray->camera_x = (2 * ray->pix) / (double)game->config.res[X] - 1;
	ray->ray_dir.x = player->dir.x + player->plane.x * ray->camera_x;
	ray->ray_dir.y = player->dir.y + player->plane.y * ray->camera_x;
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	ray->hit = 0;
}

static void		do_raycasting(t_ray *ray, t_game *game)
{
	init_ray(ray, &game->config.player, game);
	next_step(ray, &game->config.player);
	hit(ray, game);
	perp_and_height(ray, &game->config.player, game);
	ray->z_buffer[ray->pix] = ray->perp_wall_dist;
	texturisation(ray, game);
	ray->pix++;
}

static void		draw_items(t_ray *ray, t_game *game)
{
	while (ray->pix < game->config.res[X])
		do_raycasting(ray, game);
	draw_yeji(ray, game);
	draw_sprite(ray, game);
	draw_fence(ray, game);
	if (game->config.coin > 0)
		draw_coin(ray, game);
	if (check_around_chr(game, '5'))
		play_sound_effect(4);
	check_coin(game);
	check_warp(game);
}

int				raycasting(t_game *game)
{
	t_ray		*ray;

	if (!(ray = malloc(sizeof(t_ray))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(ray, sizeof(t_ray));
	if (!(ray->z_buffer = malloc(sizeof(double) * game->config.res[X])))
		exit_program("Memory allocation failed", 0);
	ft_bzero(ray->z_buffer, sizeof(double) * game->config.res[X]);
	draw_items(ray, game);
	view_skybox(game);
	if (game->config.flag[SAVE])
		create_screenshot(game->img, "screenshot");
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	free(ray->z_buffer);
	free(ray);
	return (1);
}
