/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:27:27 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 14:33:07 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	determine_side_draw(t_ray *r, t_game *g, t_line *l, double wall_x)
{
	t_img	*img;
	int		tex_x;

	img = g->tex[3];
	if (r->side == 1)
		img = g->tex[2];
	if (r->side == 2)
		img = g->tex[1];
	if (r->side == 3)
		img = g->tex[0];
	tex_x = (int)(wall_x * (double)img->width);
	if ((r->side == 0 || r->side == 1) && r->ray_dir.x > 0)
		tex_x = img->width - tex_x - 1;
	if ((r->side == 2 || r->side == 3) && r->ray_dir.y < 0)
		tex_x = img->width - tex_x - 1;
	l->y0 = r->draw_end;
	l->y1 = r->draw_start;
	l->tex_x = tex_x;
	ver_line_texture_image(l, g, img, r);
}

void		texturisation(t_ray *ray, t_game *game)
{
	t_img	*img;
	t_line	*line;
	double	wall_x;

	if (!(line = malloc(sizeof(t_line))))
		exit_program("Memory allocation failed");
	ft_bzero(line, sizeof(t_line));
	line->x = ray->pix;
	if (ray->side == 0 || ray->side == 1)
		wall_x = game->config.player.pos.y
				+ ray->perp_wall_dist * ray->ray_dir.y;
	else
		wall_x = game->config.player.pos.x
				+ ray->perp_wall_dist * ray->ray_dir.x;
	wall_x -= floor(wall_x);
	if (game->config.map[ray->map.y][ray->map.x] == '1')
		determine_side_draw(ray, game, line, wall_x);
	line->y0 = 0;
	line->y1 = ray->draw_start;
	ver_line_color_image(line, game, game->config.color[COLOR_C]);
	line->y0 = game->config.res[Y];
	line->y1 = ray->draw_end;
	ver_line_color_image(line, game, game->config.color[COLOR_F]);
	free(line);
}
