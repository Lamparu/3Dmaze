/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:31:56 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:12 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int	rayxmin(double posx, t_vec *sidedst, int mapx, double deltax)
{
	sidedst->x = (posx - mapx) * deltax;
	return (-1);
}

int	rayxmax(double posx, t_vec *sidedst, int mapx, double deltax)
{
	sidedst->x = (mapx + 1.0 - posx) * deltax;
	return (1);
}

void	check_ray(t_vec ray, t_point *step, t_vec *sidedst, t_all *all)
{
	t_vec	delta;
	t_point	map;

	map.x = (int)all->plr->pos.x;
	map.y = (int)all->plr->pos.y;
	count_delta(ray, &delta);
	if (ray.x < 0)
		step->x = rayxmin(all->plr->pos.x, sidedst, map.x, delta.x);
	else
		step->x = rayxmax(all->plr->pos.x, sidedst, map.x, delta.x);
	if (ray.y < 0)
	{
		step->y = -1;
		sidedst->y = (all->plr->pos.y - map.y) * delta.y;
	}
	else
	{
		step->y = 1;
		sidedst->y = (map.y + 1.0 - all->plr->pos.y) * delta.y;
	}
}
