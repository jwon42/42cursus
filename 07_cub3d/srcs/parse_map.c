/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:12:01 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 14:27:17 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		check_map_valid_position(int row, int col, t_config *config)
{
	int		error_cnt;

	error_cnt = 0;
	if ((check_valid_chr(config->map[row][col]) == 0) ||
		(check_valid_chr(config->map[row][col]) == 2) ||
		(check_valid_chr(config->map[row][col]) == 3))
	{
		if (col == 0 || col == (int)(ft_strlen(config->map[row]) - 1) ||
			(row == 0 || row == (config->row - 1)))
			error_cnt++;
		else
		{
			if (col >= (int)ft_strlen(config->map[row - 1]) ||
				col >= (int)ft_strlen(config->map[row + 1]) ||
				ft_isspace(config->map[row - 1][col]) ||
				ft_isspace(config->map[row + 1][col]) ||
				ft_isspace(config->map[row][col - 1]) ||
				ft_isspace(config->map[row][col + 1]))
				error_cnt++;
		}
	}
	return (error_cnt);
}

static void		check_map_format(t_config *config)
{
	int		row;
	int		col;
	int		error_cnt;

	row = 0;
	error_cnt = 0;
	while (config->map[row])
	{
		col = 0;
		while (config->map[row][col])
		{
			if (check_valid_chr(config->map[row][col]) == 3)
				save_player_info(row, col, config);
			if (check_valid_chr(config->map[row][col]) == -1)
				error_cnt++;
			error_cnt += check_map_valid_position(row, col, config);
			col++;
			if (col > config->col)
				config->col = col;
		}
		row++;
	}
	if (error_cnt > 0 || config->player.cnt != 1)
		exit_program("Map format is invalid");
}

static void		modify_map_to_rectangle(t_config *config)
{
	int			bytes;
	int			row;
	char		*new;

	row = 0;
	while (config->map[row])
	{
		bytes = ft_strlen(config->map[row]);
		if (bytes < config->col)
		{
			if (!(new = (char *)malloc(sizeof(char) * config->col + 1)))
				exit_program("Memory allocation failed");
			ft_memcpy(new, config->map[row], bytes);
			while (bytes < config->col)
				new[bytes++] = ' ';
			new[bytes] = '\0';
			free(config->map[row]);
			config->map[row] = new;
		}
		row++;
	}
}

void			parse_map(int ret, char *line, t_config *config)
{
	static char *buf = "";
	char		*tmp;
	char		*tmp2;

	check_identifiers_exist(ret, config);
	if (ft_isspace_str(line))
		exit_program("Map format is invalid");
	tmp = ft_strjoin(line, "\n");
	tmp2 = ft_strjoin(buf, tmp);
	free(tmp);
	if (*buf)
		free(buf);
	buf = tmp2;
	config->id[ID_MAP]++;
	config->row = config->id[ID_MAP];
	if (ret == 0)
	{
		config->map = ft_split(buf, '\n');
		free(buf);
		check_map_format(config);
		modify_map_to_rectangle(config);
	}
}
