/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:31:42 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:09 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

void	prepare_sprite(t_all *all)
{
	int i;

	i = 0;
	while (i < all->snum)
	{
		all->sprs[i].dst = ((all->plr->pos.x - all->sprs[i].pos.x - 0.5) *
							(all->plr->pos.x - all->sprs[i].pos.x - 0.5) +
							(all->plr->pos.y - all->sprs[i].pos.y - 0.5) *
							(all->plr->pos.y - all->sprs[i].pos.y - 0.5));
		i++;
	}
	all = bubble_sort(all);
}

void	draw_point(t_all *all, t_draw_sprite dr, int stripe, int texx)
{
	int		y;
	int		d;
	int		texy;
	int		sp_hw;
	size_t	color;

	sp_hw = (int)(ft_abs((all->info->r_y / dr.transform.y)));
	y = dr.start.y;
	while (y < dr.end.y)
	{
		d = y * 256 - all->info->r_y * 128 + sp_hw * 128;
		texy = ((d * all->tex[4]->h) / sp_hw) / 256;
		color = (size_t)((unsigned int*)all->tex[4]->data)
											[all->tex[4]->w * texy + texx];
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(all->win, stripe, y, color);
		y++;
	}
}

void	draw_stripe(t_all *all, t_draw_sprite dr)
{
	int stripe;
	int sp_screeen_x;
	int sp_hw;
	int texx;

	sp_screeen_x = (int)(((double)all->info->r_x / 2) *
							(1 + dr.transform.x / dr.transform.y));
	sp_hw = (int)(ft_abs((all->info->r_y / dr.transform.y)));
	stripe = dr.start.x;
	while (stripe < dr.end.x)
	{
		texx = (int)(256 * (stripe - (-sp_hw / 2 + sp_screeen_x)) *
				all->tex[4]->w / sp_hw) / 256;
		if (dr.transform.y > 0 && stripe > 0 && stripe < all->info->r_x &&
								dr.transform.y < all->zbuf[stripe])
			draw_point(all, dr, stripe, texx);
		stripe++;
	}
}

void	draw_sprites(t_all *all)
{
	int				i;
	t_draw_sprite	dr;
	t_vec			sprite;

	prepare_sprite(all);
	i = 0;
	while (i < all->snum)
	{
		count_transform(all, &sprite, &dr.transform, i);
		count_end_sp(all, &dr.end, dr.transform);
		count_start_sp(all, &dr.start, dr.transform);
		draw_stripe(all, dr);
		i++;
	}
}
