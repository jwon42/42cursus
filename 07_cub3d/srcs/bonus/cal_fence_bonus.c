/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_fence_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 13:14:03 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:19:52 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void		next_fence(t_fences *actual, t_fences *new, t_ray *ray)
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

void			is_fence(t_ray *ray, t_game *game)
{
	t_fences *new;
	t_fences *actual;
	t_fences save_top;

	if (!(new = malloc(sizeof(t_fences))))
		return ;
	new->next = NULL;
	new->coord.x = ray->map.x;
	new->coord.y = ray->map.y;
	actual = game->fences;
	save_top = *actual;
	if (actual->coord.x == -1 && actual->coord.y == -1)
	{
		actual->coord.x = ray->map.x;
		actual->coord.y = ray->map.y;
	}
	else
		next_fence(actual, new, ray);
	actual = &save_top;
}

void			sort_fence(t_game *g, t_fence *s, int nbr)
{
	int			i;
	double		one;
	double		two;
	t_fence		tmp;

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

t_fence			*list_to_tab_fence(t_game *game)
{
	t_fence		*rtn;
	t_fences	*save_top;
	int			count;

	save_top = game->fences;
	count = -1;
	if (!(rtn = malloc(sizeof(t_fence)
		* ft_lstsize((t_list *)game->fences))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(rtn, sizeof(t_fence)
		* ft_lstsize((t_list *)game->fences));
	while (++count > -1)
	{
		if (game->fences)
		{
			rtn[count].coord.x = game->fences->coord.x;
			rtn[count].coord.y = game->fences->coord.y;
		}
		if (game->fences->next)
			game->fences = game->fences->next;
		else
			break ;
	}
	game->fences = save_top;
	return (rtn);
}
