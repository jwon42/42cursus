/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_lifebar_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:51:36 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:40:44 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void		view_lifebar_2(t_game *game)
{
	void	*img[3];
	int		img_width;
	int		img_height;

	if (game->health == 3)
	{
		img[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/lifebar/40.xpm", &img_width, &img_height);
		mlx_put_image_to_window(game->mlx, game->win, img[0], 20, 20);
	}
	else if (game->health == 2)
	{
		img[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/lifebar/20.xpm", &img_width, &img_height);
		mlx_put_image_to_window(game->mlx, game->win, img[1], 20, 20);
	}
	else if (game->health == 1)
	{
		img[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/lifebar/0.xpm", &img_width, &img_height);
		mlx_put_image_to_window(game->mlx, game->win, img[2], 20, 20);
	}
}

void			view_lifebar(t_game *game)
{
	void	*img[2];
	int		img_width;
	int		img_height;

	if (game->health == 5)
	{
		img[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/lifebar/100.xpm", &img_width, &img_height);
		mlx_put_image_to_window(game->mlx, game->win, img[0], 20, 20);
	}
	else if (game->health == 4)
	{
		img[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/lifebar/70.xpm", &img_width, &img_height);
		mlx_put_image_to_window(game->mlx, game->win, img[1], 20, 20);
	}
	else if (game->health <= 3)
		view_lifebar_2(game);
}
