/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:42:45 by yechoi            #+#    #+#             */
/*   Updated: 2020/09/13 20:15:34 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_pipe(char **line, t_pipe *p, t_list *envs)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = -1;
	while ((*line)[++i])
	{
		if ((*line)[i] == '|')
		{
			temp = ft_substr(*line, 0, i);
			p->line = ft_strtrim(temp, " ");
			free(temp);
			temp = ft_substr(*line, i + 1, ft_strlen(*line) - i);
			temp2 = ft_strtrim(temp, " ");
			free(temp);
			*line = temp2;
			p->argv = get_argv(p->line, envs);
			return ;
		}
	}
}

void	exec_pipe_case_zero(int child, int fd[2], t_list *envs, t_pipe p)
{
	if (child == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_cmds(p.line, envs);
		exit(EXIT_SUCCESS);
	}
}

void	exec_pipe_case_one(int child, int fd[2], t_list *envs, char *line)
{
	if (child == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_cmds(line, envs);
		exit(EXIT_SUCCESS);
	}
}

void	exec_pipe(char *line, t_list *envs)
{
	int		fd[2];
	int		child[2];
	int		status[2];
	t_pipe	p;

	parse_pipe(&line, &p, envs);
	pipe(fd);
	child[0] = fork();
	exec_pipe_case_zero(child[0], fd, envs, p);
	free_double_arr(p.argv);
	free(p.line);
	child[1] = fork();
	exec_pipe_case_one(child[1], fd, envs, line);
	free(line);
	close(fd[0]);
	close(fd[1]);
	waitpid(child[1], &status[1], 0);
	waitpid(child[0], &status[0], WNOHANG);
}
