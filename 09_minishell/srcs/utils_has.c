/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_has.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <jwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:43:26 by yechoi            #+#    #+#             */
/*   Updated: 2020/09/14 11:30:04 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		has_quote(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
	}
	return (0);
}

int		has_env(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '$')
			return (1);
	}
	return (0);
}

int		has_pipe(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		if (*str == '|')
			num++;
		str++;
	}
	return (num);
}

int		has_redir(char *str)
{
	int num;

	num = 0;
	while (*str)
	{
		if (ft_strchr("><", *str))
			num++;
		str++;
	}
	return (num);
}
