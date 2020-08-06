/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_sound_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:04:12 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:20:56 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	play_bgm(void)
{
	system("afplay -v 0.40 sounds/bgm.mp3 &");
}

void	play_sound_effect(int type)
{
	if (type == 1)
		system("afplay -v 0.40 sounds/pipe.wav &");
	else if (type == 2)
		system("afplay -v 0.40 sounds/coin.wav &");
	else if (type == 3)
		system("afplay -v 0.40 sounds/open.wav &");
	else if (type == 4)
		exit_program("GAME CLEAR", 2);
}
