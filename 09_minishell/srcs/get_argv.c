/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <jwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:42:58 by yechoi            #+#    #+#             */
/*   Updated: 2020/09/14 14:38:37 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*modify_argv(char *str, t_list *envs)
{
	char	*ret;

	ret = 0;
	if (has_quote(str))
		ret = parse_quote(str, envs);
	else if (has_env(str))
		ret = parse_env(str, envs);
	free(str);
	return (ret);
}

char	**get_argv(char *line, t_list *envs)
{
	int		i;
	char	**argv;

	if (!(argv = ft_split(line, ' ')))
		return (0);
	i = -1;
	while (argv[++i])
	{
		if ((ft_strlen(argv[i]) != 1)
			&& (has_quote(argv[i]) || has_env(argv[i])))
			argv[i] = modify_argv(argv[i], envs);
	}
	return (argv);
}
