/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:31:38 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:08 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

void	count_transform(t_all *all, t_vec *sprite, t_vec *transform, size_t i)
{
	double	inv;

	sprite->x = all->sprs[i].pos.x + 0.5 - all->plr->pos.x;
	sprite->y = all->sprs[i].pos.y + 0.5 - all->plr->pos.y;
	inv = 1.0 / (all->plane.x * all->plr->dir.y
			- all->plane.y * all->plr->dir.x);
	transform->x = inv * (all->plr->dir.y * sprite->x
			- all->plr->dir.x * sprite->y);
	transform->y = inv * (-all->plane.y * sprite->x
			+ all->plane.x * sprite->y);
}

void	count_start_sp(t_all *all, t_point *start, t_vec transform)
{
	int	sp_screeen_x;
	int	sp_hw;

	sp_screeen_x = (int)(((double)all->info->r_x / 2)
			* (1 + transform.x / transform.y));
	sp_hw = (int)(ft_abs((all->info->r_y / transform.y)));
	start->y = -sp_hw / 2 + all->info->r_y / 2;
	if (start->y < 0)
		start->y = 0;
	start->x = -sp_hw / 2 + sp_screeen_x;
	if (all->info->r_y % 2)
		start->y++;
	if (start->x < 0)
		start->x = 0;
}

void	count_end_sp(t_all *all, t_point *end, t_vec transform)
{
	int	sp_screeen_x;
	int	sp_hw;

	sp_screeen_x = (int)(((double)all->info->r_x / 2)
			* (1 + transform.x / transform.y));
	sp_hw = (int)(ft_abs((all->info->r_y / transform.y)));
	end->y = sp_hw / 2 + all->info->r_y / 2;
	if (end->y >= all->info->r_y)
		end->y = (int)all->info->r_y - 1;
	end->x = sp_hw / 2 + sp_screeen_x;
	if (end->x >= all->info->r_x)
		end->x = all->info->r_x - 1;
}
