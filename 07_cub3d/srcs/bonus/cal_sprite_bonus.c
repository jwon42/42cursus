/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_sprite_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 13:14:03 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 19:19:58 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static void		next_sprite(t_sprites *actual, t_sprites *new, t_ray *ray)
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

void			is_sprite(t_ray *ray, t_game *game)
{
	t_sprites *new;
	t_sprites *actual;
	t_sprites save_top;

	if (!(new = malloc(sizeof(t_sprites))))
		return ;
	new->next = NULL;
	new->coord.x = ray->map.x;
	new->coord.y = ray->map.y;
	actual = game->sprites;
	save_top = *actual;
	if (actual->coord.x == -1 && actual->coord.y == -1)
	{
		actual->coord.x = ray->map.x;
		actual->coord.y = ray->map.y;
	}
	else
		next_sprite(actual, new, ray);
	actual = &save_top;
}

void			sort_sprite(t_game *g, t_sprite *s, int nbr)
{
	int			i;
	double		one;
	double		two;
	t_sprite	tmp;

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

t_sprite		*list_to_tab_sprite(t_game *game)
{
	t_sprite	*rtn;
	t_sprites	*save_top;
	int			count;

	save_top = game->sprites;
	count = -1;
	if (!(rtn = malloc(sizeof(t_sprite)
		* ft_lstsize((t_list *)game->sprites))))
		exit_program("Memory allocation failed", 0);
	ft_bzero(rtn, sizeof(t_sprite)
		* ft_lstsize((t_list *)game->sprites));
	while (++count > -1)
	{
		if (game->sprites)
		{
			rtn[count].coord.x = game->sprites->coord.x;
			rtn[count].coord.y = game->sprites->coord.y;
		}
		if (game->sprites->next)
			game->sprites = game->sprites->next;
		else
			break ;
	}
	game->sprites = save_top;
	return (rtn);
}
