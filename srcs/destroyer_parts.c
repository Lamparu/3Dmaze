/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer_parts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:30:02 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:37:02 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

void	img_destroy(t_all *all, t_img *img)
{
	if (!img)
		return ;
	if (all->win->mlx && img->img)
		mlx_destroy_image(all->win->mlx, img->img);
	free(img);
}

void	img_destroy_all(t_all *all)
{
	int i;

	if (!all->tex)
		return ;
	i = 0;
	while (i < 5)
	{
		img_destroy(all, all->tex[i]);
		i++;
	}
	free(all->tex);
}
