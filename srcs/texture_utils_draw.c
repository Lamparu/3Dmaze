/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:31:52 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:11 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int	draw_tex(t_all *all, t_draw *dr, int x, int y)
{
	double	tex;
	size_t	color;
	int		lineh;

	lineh = (int)(all->info->r_y / all->zbuf[x]);
	dr->step = (double)all->tex[dr->texnum]->h / lineh;
	tex = (dr->draw.x - (double)all->info->r_y / 2 + (double)lineh / 2)
		* dr->step;
	while (y < dr->draw.y)
	{
		dr->tex.y = (int)tex & (all->tex[dr->texnum]->h - 1);
		tex += dr->step;
		color = (int)((unsigned int *)all->tex[dr->texnum]->data)
		[all->tex[dr->texnum]->h * dr->tex.y + dr->tex.x];
		my_mlx_pixel_put(all->win, x, y, color);
		y++;
	}
	return (y);
}

/*
** side == 0 => left/right
** ray.x > 0 => right
** ray.y > 0 => south
*/

int	choose_tex(t_draw dr)
{
	if (dr.side == 0)
	{
		if (dr.ray.x > 0)
			return (1);
		else
			return (3);
	}
	else
	{
		if (dr.ray.y > 0)
			return (2);
		else
			return (0);
	}
}

int	change_side(t_vec *sidedst, t_vec delta, t_point *map, t_point *step)
{
	if (sidedst->x < sidedst->y)
	{
		sidedst->x += delta.x;
		map->x += step->x;
		return (0);
	}
	else
	{
		sidedst->y += delta.y;
		map->y += step->y;
		return (1);
	}
}

int	hit_wall(t_all *all, t_point *map, t_point *step, t_vec ray)
{
	int		hit;
	int		side;
	t_vec	sidedst;
	t_vec	delta;

	hit = 0;
	count_delta(ray, &delta);
	check_ray(ray, step, &sidedst, all);
	map->x = floor(all->plr->pos.x);
	map->y = floor(all->plr->pos.y);
	while (hit == 0)
	{
		side = change_side(&sidedst, delta, map, step);
		if (all->map[map->y][map->x] == '1')
			hit = 1;
	}
	return (side);
}
