/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:13:50 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 14:27:38 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_filename_ext(char *filename, char *ext)
{
	int		filename_len;
	int		ext_len;
	char	*tmp;

	filename_len = ft_strlen(filename);
	ext_len = ft_strlen(ext);
	if ((tmp = ft_strrchr(filename, '.') + 1) == NULL)
		return (0);
	if (filename_len < ext_len + 2)
		return (0);
	if (tmp + 1 == NULL)
		return (0);
	if (ft_strncmp(tmp, ext, ext_len))
		return (0);
	return (1);
}

void	check_identifiers_exist(int ret, t_config *config)
{
	int		idx;

	idx = 0;
	while (ret == 1 && idx < ID_MAP)
	{
		if (config->id[idx] != 1)
			exit_program("Some identifiers does not exist or overlap");
		idx++;
	}
	if (ret == 0 && config->id[ID_MAP] == 0)
		exit_program("Map infomation does not exist");
}

int		check_valid_chr(char c)
{
	if (c == '0')
		return (0);
	if (c == '1')
		return (1);
	if (c == '2')
		return (2);
	if (ft_strchr("NSWE", c))
		return (3);
	if (c == ' ')
		return (4);
	return (-1);
}
