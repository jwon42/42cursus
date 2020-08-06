/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 13:14:03 by jwon              #+#    #+#             */
/*   Updated: 2020/08/04 14:36:55 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	actual = game->sprites_on_screen;
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

t_sprite		*list_to_tab(t_game *game)
{
	t_sprite	*rtn;
	t_sprites	*save_top;
	int			count;

	save_top = game->sprites_on_screen;
	count = -1;
	if (!(rtn = malloc(sizeof(t_sprite)
		* ft_lstsize((t_list *)game->sprites_on_screen))))
		exit_program("Memory allocation failed");
	ft_bzero(rtn, sizeof(t_sprite)
		* ft_lstsize((t_list *)game->sprites_on_screen));
	while (++count > -1)
	{
		if (game->sprites_on_screen)
		{
			rtn[count].coord.x = game->sprites_on_screen->coord.x;
			rtn[count].coord.y = game->sprites_on_screen->coord.y;
		}
		if (game->sprites_on_screen->next)
			game->sprites_on_screen = game->sprites_on_screen->next;
		else
			break ;
	}
	game->sprites_on_screen = save_top;
	return (rtn);
}
