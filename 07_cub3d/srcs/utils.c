/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:19:28 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 13:45:46 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_program(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putchar_fd('\"', 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\"', 1);
	ft_putchar_fd('\n', 1);
	exit(EXIT_FAILURE);
}
