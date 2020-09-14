/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:43:30 by yechoi            #+#    #+#             */
/*   Updated: 2020/09/13 19:03:18 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_single_redir(char *command, int i)
{
	if (command[i] == '>' && command[i - 1] != '>' && command[i + 1] != '>')
		return (1);
	return (0);
}

int		find_redir_type(char *command, int i)
{
	if (command[i] == '>' && command[i + 1] == '>')
		return (DREDIR);
	else if (is_single_redir(command, i))
		return (REDIR);
	return (BREDIR);
}

int		has_redir_syntax_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(" \n", str[i]))
			return (0);
		i++;
	}
	return (1);
}
