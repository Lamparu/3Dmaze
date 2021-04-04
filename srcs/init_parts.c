/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:30:39 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:39:48 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

t_map	*init_map_null(t_map *map)
{
	map->r_y = 0;
	map->r_x = 0;
	map->text->no = NULL;
	map->text->so = NULL;
	map->text->ea = NULL;
	map->text->we = NULL;
	map->text->sprite = NULL;
	map->floor->blue = -1;
	map->floor->green = -1;
	map->floor->red = -1;
	map->ceil->blue = -1;
	map->ceil->green = -1;
	map->ceil->red = -1;
	return (map);
}

t_map	*init_map(t_map *map)
{
	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->text = malloc(sizeof(t_texture))))
	{
		free(map);
		return (NULL);
	}
	if (!(map->ceil = malloc(sizeof(t_color))))
	{
		free(map->text);
		free(map);
		return (NULL);
	}
	if (!(map->floor = malloc(sizeof(t_color))))
	{
		free(map->ceil);
		free(map->text);
		free(map);
		return (NULL);
	}
	map = init_map_null(map);
	return (map);
}

t_plr	*init_plr(t_plr *plr)
{
	if (!(plr = malloc(sizeof(t_plr))))
		return (NULL);
	plr->dir.x = 0;
	plr->dir.y = 0;
	plr->pos.x = -1;
	plr->pos.y = -1;
	return (plr);
}

t_win	*init_win(t_win *win)
{
	if (!(win = malloc(sizeof(t_win))))
		return (NULL);
	win->line_l = 0;
	win->en = 0;
	win->bpp = 0;
	win->img = NULL;
	win->mlx = NULL;
	win->win = NULL;
	win->addr = NULL;
	return (win);
}
