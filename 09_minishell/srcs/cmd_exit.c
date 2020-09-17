/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <jwon@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:46:55 by jwon              #+#    #+#             */
/*   Updated: 2020/09/17 15:18:52 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_isdigit_str(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}

void			cmd_exit(char **argv)
{
	int	argc;

	argc = 0;
	while (argv[argc] != NULL)
		argc++;
	if (argc == 1)
	{
		ft_putendl_fd("exit", 1);
		exit(EXIT_SUCCESS);
	}
	else if (argc == 2 && ft_isdigit_str(argv[1]))
	{
		exit(ft_atoi(argv[1]));
	}
	else if (argc > 2 && ft_isdigit_str(argv[1]))
		ft_putendl_fd("exit: too many arguments", 1);
	else
	{
		ft_putstr_fd("exit: numeric argument required", 1);
		exit(2);
	}
}
