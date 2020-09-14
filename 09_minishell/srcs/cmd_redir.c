/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:42:00 by yechoi            #+#    #+#             */
/*   Updated: 2020/09/13 19:00:49 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		do_redir(t_redir *r, t_list *envs)
{
	int		fd;
	char	*path;

	fd = open(r->argv[r->argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (fd < 0)
	{
		ft_puterror_fd(r->argv[r->argc - 1], ": No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	if (!(path = find_path(r->cmds[0], envs)))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (!exec_builtin(r->argv[r->argc - 1], envs) &&
		(execve(path, r->cmds, g_envp) == -1))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	free(path);
	free_double_arr(r->cmds);
	return (EXIT_SUCCESS);
}

static int		do_dredir(t_redir *r, t_list *envs)
{
	int		fd;
	char	*path;

	fd = open(r->argv[r->argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0744);
	if (fd < 0)
	{
		ft_puterror_fd(r->argv[r->argc - 1], ": No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	if (!(path = find_path(r->cmds[0], envs)))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (!exec_builtin(r->argv[r->argc - 1], envs) &&
		(execve(path, r->cmds, g_envp) == -1))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	free(path);
	free_double_arr(r->cmds);
	return (EXIT_SUCCESS);
}

static int		do_bredir(t_redir *r, t_list *envs)
{
	int		fd;
	char	*path;

	fd = open(r->argv[r->argc - 1], O_RDONLY, 0644);
	if (fd < 0)
	{
		ft_puterror_fd(r->argv[r->argc - 1], ": No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	if (!(path = find_path(r->cmds[0], envs)))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	dup2(fd, STDIN_FILENO);
	close(fd);
	if (!exec_builtin(r->argv[r->argc - 1], envs) &&
		(execve(path, r->cmds, g_envp) == -1))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	free(path);
	free_double_arr(r->cmds);
	return (EXIT_SUCCESS);
}

void			cmd_redir(t_redir *r, t_list *envs)
{
	int		i;
	int		ret;
	int		status;
	pid_t	child;

	i = 0;
	child = fork();
	if (child == 0)
	{
		if (r->types[r->argc - 2] == REDIR)
			ret = do_redir(r, envs);
		else if (r->types[r->argc - 2] == DREDIR)
			ret = do_dredir(r, envs);
		else
			ret = do_bredir(r, envs);
		exit(ret);
	}
	wait(&status);
	g_exit_value = status / 256;
	free(r->types);
	free_double_arr(r->argv);
	free_double_arr(r->cmds);
}
