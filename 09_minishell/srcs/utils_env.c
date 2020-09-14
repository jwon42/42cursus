/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <jwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:57:13 by jwon              #+#    #+#             */
/*   Updated: 2020/09/14 14:46:40 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_valid_env(char *arg)
{
	if (ft_isdigit(arg[0]) || arg[0] == '=')
		return (0);
	if (ft_strchr(arg, '='))
		return (1);
	return (0);
}

int			is_exist_key(char *key, t_list *envs)
{
	int		len;
	int		len_find;
	int		len_exist;

	len_find = ft_strlen(key);
	len_exist = ft_strlen((char *)((t_env *)envs->content)->key);
	len = (len_find > len_exist) ? len_find : len_exist;
	if (ft_strncmp(key, ((t_env *)envs->content)->key, len) == 0)
		return (1);
	return (0);
}

char		*find_value(char *key, t_list *envs)
{
	while (envs)
	{
		if (is_exist_key(key, envs))
			return (((t_env *)envs->content)->value);
		envs = envs->next;
	}
	return ("");
}

char		*find_path(char *argv, t_list *envs)
{
	int			idx;
	char		*temp;
	char		*new_path;
	char		**paths;
	struct stat	s;

	if (!(temp = find_value("PATH", envs)))
		return (NULL);
	paths = ft_split(temp, ':');
	idx = -1;
	while (paths[++idx])
	{
		temp = ft_strjoin("/", argv);
		new_path = ft_strjoin(paths[idx], temp);
		free(temp);
		if (stat(new_path, &s) == 0)
		{
			free_double_arr(paths);
			return (new_path);
		}
		free(new_path);
	}
	free_double_arr(paths);
	return (ft_strdup(argv));
}
