/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <jwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:49:19 by jwon              #+#    #+#             */
/*   Updated: 2020/09/17 15:51:40 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int signo)
{
	int		status;

	if (signo == SIGINT)
	{
		ft_putstr_fd("\b\b  \b\b", 1);
		ft_putstr_fd("\n", 1);
		// show_prompt(g_env_user);
		g_exit_value = 1;
		return ;
	}
	else if (signo == SIGQUIT)
	{
		signo = wait(&status);
		ft_putstr_fd("\b\b  \b\b", 1);
		g_exit_value = 127;
		if (signo != -1)
			ft_putstr_fd("^\\Quit: 3\n", 1);
	}
	return ;
}
