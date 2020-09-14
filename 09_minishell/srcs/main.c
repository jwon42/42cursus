/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:45:47 by jwon              #+#    #+#             */
/*   Updated: 2020/09/13 22:48:16 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup(t_list *envs)
{
	g_exit_value = 0;
	g_env_user = find_value("USER", envs);
	show_art();
	signal(SIGINT, (void *)handle_signal);
	signal(SIGQUIT, (void *)handle_signal);
}

int		main(int argc, char **argv, char **envp)
{
	int		i;
	char	*line;
	char	**cmds;
	t_list	*envs;

	g_envp = envp;
	envs = get_envs(argc, argv, envp);
	setup(envs);
	line = 0;
	while (1)
	{
		show_prompt(g_env_user);
		if (!input_from_prompt(&line))
			continue ;
		if ((cmds = get_cmds(line)) == NULL)
			continue ;
		i = -1;
		while (cmds[++i])
		{
			exec_cmds(cmds[i], envs);
			free(cmds[i]);
		}
		free(cmds);
	}
	return (0);
}
