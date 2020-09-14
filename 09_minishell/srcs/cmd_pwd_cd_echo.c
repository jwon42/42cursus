/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd_cd_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <jwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:48:08 by jwon              #+#    #+#             */
/*   Updated: 2020/09/14 14:38:08 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_pwd(void)
{
	char	*pwd;

	pwd = getcwd(0, 1024);
	ft_putendl_fd(pwd, 1);
	free(pwd);
}

void	cmd_cd(char **argv, t_list *envs)
{
	char	*path;

	path = 0;
	if (argv[1] == NULL || ((argv[1] != NULL) &&
		(ft_strlen(argv[1]) == 1) && (argv[1][0] == '~')))
	{
		path = find_value("HOME", envs);
		if (chdir(path) == -1)
			ft_putendl_fd(strerror(errno), 2);
		return ;
	}
	else if (*argv[1] == '$')
	{
		path = find_value(argv[1] + 1, envs);
		if (chdir(path) == -1)
			ft_putendl_fd(strerror(errno), 2);
		return ;
	}
	if (chdir(argv[1]) == -1)
		ft_putendl_fd(strerror(errno), 2);
}

void	cmd_echo(char **argv)
{
	int		idx;
	int		endl;

	idx = 0;
	endl = 0;
	while (argv[++idx])
	{
		while (argv[idx] && (endl + 1) == idx &&
		!ft_strncmp(argv[idx], "-n", ft_strlen(argv[idx])))
		{
			if (argv[idx + 1] == NULL)
				return ;
			endl++;
			idx++;
		}
		ft_putstr_fd(argv[idx], 1);
		if (argv[idx + 1] != NULL)
			ft_putstr_fd(" ", 1);
	}
	if (!endl)
		ft_putstr_fd("\n", 1);
}
