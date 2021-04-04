/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:30:44 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:39:51 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

void	*init_err(t_all *all, char *er)
{
	printf("Error\nMalloc %s error", er);
	if (all)
		all_destroy(all);
	return (NULL);
}

t_all	*init_all_null(t_all *all)
{
	all->map = NULL;
	all->maph = 0;
	all->plane.x = 0;
	all->plane.y = 0;
	all->snum = 0;
	all->zbuf = NULL;
	all->sprs = NULL;
	all->on = 0;
	all->tex = NULL;
	all->key.w = 0;
	all->key.a = 0;
	all->key.s = 0;
	all->key.d = 0;
	all->key.right = 0;
	all->key.left = 0;
	return (all);
}

t_all	*init_all(void)
{
	t_all *all;

	if (!(all = malloc(sizeof(t_all))))
		return (init_err(NULL, "all"));
	if (!(all->info = init_map(all->info)))
		return (init_err(all, "info"));
	if (!(all->plr = init_plr(all->plr)))
		return (init_err(all, "player"));
	if (!(all->win = init_win(all->win)))
		return (init_err(all, "win"));
	all = init_all_null(all);
	return (all);
}

t_img	**init_imgs(t_all *all)
{
	int		i;
	t_img	**imgs;

	i = 0;
	if (!(imgs = malloc(sizeof(t_img*) * 6)))
		exit_err(all, "Malloc", 1);
	while (i < 5)
	{
		if (!(imgs[i] = malloc(sizeof(t_img))))
			exit_err(all, "Malloc img", 3);
		if (!(imgs[i]->img = mlx_xpm_file_to_image(all->win->mlx,
				get_img_path(all, i), &imgs[i]->w, &imgs[i]->h)))
			exit_err(all, "MLX img", 3);
		if (!(imgs[i]->data = mlx_get_data_addr(imgs[i]->img, &imgs[i]->bpp,
				&imgs[i]->line_l, &imgs[i]->en)))
			exit_err(all, "MLX address", 3);
		i++;
	}
	imgs[5] = NULL;
	return (imgs);
}
