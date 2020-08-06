/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:19:28 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:21:12 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	exit_program(char *str, int status)
{
	system("killall afplay");
	if (status == 0)
		ft_putstr_fd("Error\n", 1);
	ft_putchar_fd('\"', 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\"', 1);
	ft_putchar_fd('\n', 1);
	if (status == 0)
	{
		system("afplay -v 0.40 sounds/die.wav");
		exit(EXIT_FAILURE);
	}
	else if (status == 1)
	{
		system("afplay -v 0.40 sounds/die.wav");
		exit(EXIT_SUCCESS);
	}
	else if (status == 2)
	{
		system("afplay -v 0.40 sounds/game_clear.wav");
		exit(EXIT_SUCCESS);
	}
	else if (status == 3)
		exit(EXIT_SUCCESS);
}
