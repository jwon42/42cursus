/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:23:23 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 14:17:18 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		pixel_put_to_image(int color, int x, int y, t_img *img)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	img->data[y * img->size_l + x * img->bpp / 8] = r;
	img->data[y * img->size_l + x * img->bpp / 8 + 1] = g;
	img->data[y * img->size_l + x * img->bpp / 8 + 2] = b;
}

void		ver_line_color_image(t_line *line, t_game *game, int color)
{
	int y;
	int y_max;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		y_max = line->y1;
	}
	else
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			pixel_put_to_image(color, line->x, y, game->img);
			y++;
		}
	}
}

static void	texture_on_img(t_line *line, t_img *tex, t_game *game, t_ray *ray)
{
	int d;

	d = line->y * tex->size_l -
		(game->config.res[Y] * game->config.player.cam_height) *
		tex->size_l / 2 + ray->line_height * tex->size_l / 2;
	line->tex_y = ((d * tex->height) / ray->line_height) / tex->size_l;
	game->img->data[line->y * game->img->size_l + line->x
					* game->img->bpp / 8] = tex->data[line->tex_y
					* tex->size_l + line->tex_x * (tex->bpp / 8)];
	game->img->data[line->y * game->img->size_l + line->x
					* game->img->bpp / 8 + 1] = tex->data[line->tex_y
					* tex->size_l + line->tex_x * (tex->bpp / 8)
					+ 1];
	game->img->data[line->y * game->img->size_l + line->x
					* game->img->bpp / 8 + 2] = tex->data[line->tex_y
					* tex->size_l + line->tex_x * (tex->bpp / 8)
					+ 2];
}

void		ver_line_texture_image(t_line *l, t_game *g, t_img *t, t_ray *r)
{
	int y_max;

	if (l->y0 < l->y1)
	{
		l->y = l->y0;
		y_max = l->y1;
	}
	else
	{
		l->y = l->y1;
		y_max = l->y0;
	}
	if (l->y >= 0)
	{
		while (l->y < y_max)
		{
			texture_on_img(l, t, g, r);
			l->y++;
		}
	}
}

t_img		*new_image(t_game *game, int x, int y)
{
	t_img *img;

	if (!(img = malloc(sizeof(t_img))))
		exit_program("Memory allocation failed");
	ft_bzero(img, sizeof(t_img));
	if (!(img->img = mlx_new_image(game->mlx, x, y)))
		exit_program("Memory allocation failed");
	img->data = mlx_get_data_addr(img->img, &img->bpp,
				&img->size_l, &img->endian);
	img->width = x;
	img->height = y;
	return (img);
}
