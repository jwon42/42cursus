/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_coin_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 13:14:03 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:19:53 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void		next_coin(t_coins *actual, t_coins *new, t_ray *ray)
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

void			is_coin(t_ray *ray, t_game *game)
{
	t_coins *new;
	t_coins *actual;
	t_coins save_top;

	if (!(new = malloc(sizeof(t_coins))))
		return ;
	new->next = NULL;
	new->coord.x = ray->map.x;
	new->coord.y = ray->map.y;
	actual = game->coins;
	save_top = *actual;
	if (actual->coord.x == -1 && actual->coord.y == -1)
	{
		actual->coord.x = ray->map.x;
		actual->coord.y = ray->map.y;
	}
	else
		next_coin(actual, new, ray);
	actual = &save_top;
}

void			sort_coin(t_game *g, t_coin *s, int nbr)
{
	int			i;
	double		one;
	double		two;
	t_coin		tmp;

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

t_coin			*list_to_tab_coin(t_game *game)
{
	t_coin		*rtn;
	t_coins		*save_top;
	int			count;

	save_top = game->coins;
	count = -1;
	if (!(rtn = malloc(sizeof(t_coin)
		* ft_lstsize((t_list *)game->coins))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(rtn, sizeof(t_coin)
		* ft_lstsize((t_list *)game->coins));
	while (++count > -1)
	{
		if (game->coins)
		{
			rtn[count].coord.x = game->coins->coord.x;
			rtn[count].coord.y = game->coins->coord.y;
		}
		if (game->coins->next)
			game->coins = game->coins->next;
		else
			break ;
	}
	game->coins = save_top;
	return (rtn);
}
