/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:31:47 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:10 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

void	count_delta(t_vec ray, t_vec *delta)
{
	if (ray.y == 0)
		delta->x = 0;
	else
	{
		if (ray.x == 0)
			delta->x = 1;
		else
			delta->x = ft_abs(1 / ray.x);
	}
	if (ray.x == 0)
		delta->y = 0;
	else
	{
		if (ray.y == 0)
			delta->y = 1;
		else
			delta->y = ft_abs(1 / ray.y);
	}
}

int	count_start(t_all *all, int x)
{
	int	h;
	int	lineh;
	int	start;

	h = all->info->r_y;
	lineh = (int)(h / all->zbuf[x]);
	start = -1 * lineh / 2 + (h / 2);
	if (start < 0)
		start = 0;
	return (start);
}

int	count_end(t_all *all, int x)
{
	int	h;
	int	lineh;
	int	end;

	h = all->info->r_y;
	lineh = (int)(h / all->zbuf[x]);
	end = lineh / 2 + (h / 2);
	if (end >= h)
		end = h - 1;
	return (end);
}

double	count_wallx(t_all *all, int x, t_draw dr)
{
	double	wallx;

	if (dr.side == 0)
		wallx = all->plr->pos.y + all->zbuf[x] * dr.ray.y;
	else
		wallx = all->plr->pos.x + all->zbuf[x] * dr.ray.x;
	wallx -= floor(wallx);
	return (wallx);
}
