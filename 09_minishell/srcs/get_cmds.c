/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:43:03 by yechoi            #+#    #+#             */
/*   Updated: 2020/09/13 17:43:04 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		has_semicolon_syntax_error(const char *line)
{
	int		i;
	char	*temp;

	i = -1;
	temp = ft_strtrim(line, " ");
	if (temp[0] == ';')
	{
		free(temp);
		return (1);
	}
	while (temp[++i])
	{
		if (temp[i] == ';' && temp[i + 1] == ';')
		{
			free(temp);
			return (1);
		}
	}
	free(temp);
	return (0);
}

char			**get_cmds(char *line)
{
	int		i;
	int		empty;
	char	*temp;
	char	**cmds;

	empty = 0;
	cmds = ft_split(line, ';');
	i = -1;
	while (cmds[++i])
	{
		temp = ft_strtrim(cmds[i], " ");
		empty = (!temp || !(*temp)) ? 1 : 0;
		free(cmds[i]);
		!empty ? cmds[i] = temp : 0;
	}
	if (empty || has_semicolon_syntax_error(line))
	{
		free(cmds);
		ft_putendl_fd("syntax error near unexpected token `;'", 2);
		free(line);
		return (NULL);
	}
	free(line);
	return (cmds);
}
