/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:32:00 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:16 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

void	count_raydir(t_all *all, t_vec *ray, int x)
{
	t_vec	dir;
	t_vec	plane;
	double	camera;

	dir.x = all->plr->dir.x;
	dir.y = all->plr->dir.y;
	plane.x = all->plane.x;
	plane.y = all->plane.y;
	camera = 2 * x / (double)all->info->r_x - 1;
	ray->x = dir.x + plane.x * camera;
	ray->y = dir.y + plane.y * camera;
}

double	count_perpwall(t_all *all, t_draw *dr)
{
	t_point	map;
	t_point	step;

	dr->side = hit_wall(all, &map, &step, dr->ray);
	if (dr->side == 0)
		return ((map.x - all->plr->pos.x + (double)(1 - step.x) / 2)
			/ dr->ray.x);
	else
		return ((map.y - all->plr->pos.y + (double)(1 - step.y) / 2)
			/ dr->ray.y);
}

void	prepare_draw(t_all *all, t_draw *dr, int x)
{
	double	wallx;

	dr->draw.x = count_start(all, x);
	dr->draw.y = count_end(all, x);
	wallx = count_wallx(all, x, *dr);
	dr->texnum = choose_tex(*dr);
	dr->tex.x = (int)(wallx * (double)all->tex[dr->texnum]->w);
}

void	draw_column(t_all *all, t_draw *dr, int x)
{
	int		y;
	int		color;

	color = get_color(all->info->ceil);
	y = -1;
	while (++y < dr->draw.x)
		my_mlx_pixel_put(all->win, x, y, color);
	y = draw_tex(all, dr, x, y);
	color = get_color(all->info->floor);
	y--;
	while (++y < all->info->r_y - 1)
		my_mlx_pixel_put(all->win, x, y, color);
}

void	draw_texture(t_all *all)
{
	int		x;
	t_draw	dr;

	if (!all->tex)
		all->tex = init_imgs(all);
	x = 0;
	while (x < all->info->r_x)
	{
		count_raydir(all, &dr.ray, x);
		all->zbuf[x] = count_perpwall(all, &dr);
		prepare_draw(all, &dr, x);
		draw_column(all, &dr, x);
		x++;
	}
}
