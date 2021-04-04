/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:30:19 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:39:36 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

void	my_mlx_pixel_put(t_win *win, double x, double y, size_t color)
{
	char	*dst;

	dst = win->addr + ((int)y * win->line_l + (int)x * (win->bpp / 8));
	*(unsigned int*)dst = color;
}

int		draw_screen(t_all *all)
{
	if (all->on == 1)
	{
		mlx_clear_window(all->win->mlx, all->win->win);
		draw_texture(all);
		if (all->snum > 0)
			draw_sprites(all);
	}
	else
	{
		all_destroy(all);
		exit(0);
	}
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	return (0);
}
