/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_yeji_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 13:14:03 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:20:00 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void		next_yeji(t_yejis *actual, t_yejis *new, t_ray *ray)
{
	while (1)
	{
		if (actual->coord.x == ray->map.x && actual->coord.y == ray->map.y)
		{
			free(new);
			break ;
		}
		if ((actual->coord.x != ray->map.x || actual->coord.y != ray->map.y)
			&& !actual->next)
		{
			actual->next = new;
			break ;
		}
		if (actual->next)
			actual = actual->next;
		else
		{
			free(new);
			break ;
		}
	}
}

void			is_yeji(t_ray *ray, t_game *game)
{
	t_yejis *new;
	t_yejis *actual;
	t_yejis save_top;

	if (!(new = malloc(sizeof(t_yejis))))
		return ;
	new->next = NULL;
	new->coord.x = ray->map.x;
	new->coord.y = ray->map.y;
	actual = game->yejis;
	save_top = *actual;
	if (actual->coord.x == -1 && actual->coord.y == -1)
	{
		actual->coord.x = ray->map.x;
		actual->coord.y = ray->map.y;
	}
	else
		next_yeji(actual, new, ray);
	actual = &save_top;
}

void			sort_yeji(t_game *g, t_yeji *s, int nbr)
{
	int			i;
	double		one;
	double		two;
	t_yeji		tmp;

	i = 0;
	while (i < nbr && i + 1 != nbr)
	{
		one = ((g->config.player.pos.x - s[i].coord.x)
		* (g->config.player.pos.x - s[i].coord.x) + (g->config.player.pos.y
		- s[i].coord.y) * (g->config.player.pos.y - s[i].coord.y));
		two = ((g->config.player.pos.x - s[i + 1].coord.x)
		* (g->config.player.pos.x - s[i + 1].coord.x) + (g->config.player.pos.y
		- s[i + 1].coord.y) * (g->config.player.pos.y - s[i + 1].coord.y));
		if (one < two)
		{
			tmp = s[i];
			s[i] = s[i + 1];
			s[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

t_yeji			*list_to_tab_yeji(t_game *game)
{
	t_yeji		*rtn;
	t_yejis		*save_top;
	int			count;

	save_top = game->yejis;
	count = -1;
	if (!(rtn = malloc(sizeof(t_yeji)
		* ft_lstsize((t_list *)game->yejis))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(rtn, sizeof(t_yeji)
		* ft_lstsize((t_list *)game->yejis));
	while (++count > -1)
	{
		if (game->yejis)
		{
			rtn[count].coord.x = game->yejis->coord.x;
			rtn[count].coord.y = game->yejis->coord.y;
		}
		if (game->yejis->next)
			game->yejis = game->yejis->next;
		else
			break ;
	}
	game->yejis = save_top;
	return (rtn);
}
