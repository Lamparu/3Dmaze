/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:30:55 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:39:53 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int		key_press(int key, t_all *all)
{
	if (key == 2)
		all->key.d = 1;
	else if (key == 124)
		all->key.right = 1;
	else if (key == 0)
		all->key.a = 1;
	else if (key == 123)
		all->key.left = 1;
	else if (key == 13)
		all->key.w = 1;
	else if (key == 1)
		all->key.s = 1;
	else if (key == 53)
	{
		all_destroy(all);
		exit(0);
	}
	return (0);
}

int		key_unpress(int key, t_all *all)
{
	if (key == 2)
		all->key.d = 0;
	else if (key == 124)
		all->key.right = 0;
	else if (key == 0)
		all->key.a = 0;
	else if (key == 123)
		all->key.left = 0;
	else if (key == 13)
		all->key.w = 0;
	else if (key == 1)
		all->key.s = 0;
	return (0);
}

void	rotate(t_all *all, int side)
{
	all->plr->dir = vec_rotate(all->plr->dir, (M_PI_4 * side) * RS);
	all->plane = vec_rotate(all->plane, (M_PI_4 * side) * RS);
}

int		handle_key(t_all *all)
{
	if (all->key.w)
	{
		if (check_position(all, all->plr->pos.x,
							all->plr->pos.y + all->plr->dir.y * MS))
			all->plr->pos.y += all->plr->dir.y * MS;
		if (check_position(all, all->plr->pos.x + all->plr->dir.x * MS,
								all->plr->pos.y))
			all->plr->pos.x += all->plr->dir.x * MS;
	}
	if (all->key.s)
	{
		if (check_position(all, all->plr->pos.x,
							all->plr->pos.y - all->plr->dir.y * MS))
			all->plr->pos.y -= all->plr->dir.y * MS;
		if (check_position(all, all->plr->pos.x - all->plr->dir.x * MS,
								all->plr->pos.y))
			all->plr->pos.x -= all->plr->dir.x * MS;
	}
	if (all->key.d || all->key.right)
		rotate(all, 1);
	if (all->key.a || all->key.left)
		rotate(all, -1);
	draw_screen(all);
	return (0);
}

int		check_position(t_all *all, size_t x, size_t y)
{
	if (all->map[y][x] != '1')
		return (1);
	return (0);
}
