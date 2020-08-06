/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:36:12 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 14:17:47 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		set_dir(double x, double y, t_config *config)
{
	config->player.dir.x = x;
	config->player.dir.y = y;
}

static void		set_plane(double x, double y, t_config *config)
{
	config->player.plane.x = x;
	config->player.plane.y = y;
}

static void		init_player_fov(t_config *config)
{
	if (config->player.id == 'N')
	{
		set_dir(0.0, -1.0, config);
		set_plane(0.66, 0.0, config);
	}
	else if (config->player.id == 'S')
	{
		set_dir(0.0, 1.0, config);
		set_plane(-0.66, 0.0, config);
	}
	else if (config->player.id == 'W')
	{
		set_dir(-1.0, 0.0, config);
		set_plane(0.0, -0.66, config);
	}
	else if (config->player.id == 'E')
	{
		set_dir(1.0, 0.0, config);
		set_plane(0.0, 0.66, config);
	}
	config->player.cam_height = 1.0;
}

void			save_player_info(int row, int col, t_config *config)
{
	config->player.pos.x = (double)col;
	config->player.pos.y = (double)row;
	config->player.id = config->map[row][col];
	config->player.cnt++;
	init_player_fov(config);
}
