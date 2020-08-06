/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:14:09 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 14:24:16 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				check_texture_id(char *line, t_config *config)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
	{
		config->id[ID_NO]++;
		return (TEX_NO);
	}
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
	{
		config->id[ID_SO]++;
		return (TEX_SO);
	}
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
	{
		config->id[ID_WE]++;
		return (TEX_WE);
	}
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
	{
		config->id[ID_EA]++;
		return (TEX_EA);
	}
	else
	{
		config->id[ID_S]++;
		return (TEX_S);
	}
}

void			parse_texture(char *line, int id, t_config *config)
{
	char		*tmp;

	if (ft_isspace_str(line))
		exit_program("Texture filename is empty");
	tmp = ft_strtrim(line, " ");
	if (check_filename_ext(tmp, "xpm") == 0)
		exit_program("Texture filename extension is invalid");
	config->texture[id] = ft_strdup(tmp);
	free(tmp);
}

int				check_color_id(char *line, t_config *config)
{
	if (line[0] == 'F' && line[1] == ' ')
	{
		config->id[ID_F]++;
		return (COLOR_F);
	}
	else
	{
		config->id[ID_C]++;
		return (COLOR_C);
	}
}

static void		check_color_format(char *line)
{
	int			idx;
	int			comma_cnt;

	idx = 0;
	comma_cnt = 0;
	while (line[idx])
	{
		if (ft_isdigit(line[idx]) || line[idx] == ',')
		{
			if (line[idx] == ',')
				comma_cnt++;
		}
		else
			break ;
		idx++;
	}
	if (comma_cnt != 2 || idx != ((int)ft_strlen(line)))
		exit_program("RGB color format is invalid");
}

void			parse_color(char *line, int id, t_config *config)
{
	int			color[3];
	char		**buf;
	char		*tmp;
	int			idx;

	if (ft_isspace_str(line))
		exit_program("RGB color value is empty");
	tmp = ft_strtrim(line, " ");
	check_color_format(tmp);
	buf = ft_split(tmp, ',');
	free(tmp);
	color[0] = ft_atoi(buf[0]);
	color[1] = ft_atoi(buf[1]);
	color[2] = ft_atoi(buf[2]);
	idx = -1;
	while (++idx < 3)
		free(buf[idx]);
	free(buf);
	if (!(0 <= color[0] && color[0] <= 255) ||
		!(0 <= color[1] && color[1] <= 255) ||
		!(0 <= color[2] && color[2] <= 255))
		exit_program("RGB color is out of expected range");
	config->color[id] = (color[0] * 256 * 256) + (color[1] * 256) + color[2];
}
