/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:30:06 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:39:33 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

void	win_destroy(t_win *win)
{
	if (win == NULL)
		return ;
	if (win->mlx && win->img)
		mlx_destroy_image(win->mlx, win->img);
	if (win->mlx && win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
		free(win->mlx);
	free(win);
}

void	info_tex_destroy(t_texture *tex)
{
	if (!tex)
		return ;
	if (tex->no)
		free(tex->no);
	if (tex->so)
		free(tex->so);
	if (tex->ea)
		free(tex->ea);
	if (tex->we)
		free(tex->we);
	if (tex->sprite)
		free(tex->sprite);
	free(tex);
}

void	*info_destroy(t_map *map, const char *er)
{
	if (!map)
		return (NULL);
	if (map->floor)
		free(map->floor);
	if (map->ceil)
		free(map->ceil);
	info_tex_destroy(map->text);
	free(map);
	if (er && ft_strcmp(er, "UNKNOWN"))
		printf("Error\nError with content");
	else if (er)
		printf("Error\nError with %s path", er);
	return (NULL);
}

void	*map_destroy(char **map, size_t h)
{
	size_t	y;

	if (!map)
		return (NULL);
	y = 0;
	while (y < h)
	{
		if (map[y])
			free(map[y]);
		y++;
	}
	free(map);
	return (NULL);
}

int	all_destroy(t_all *all)
{
	if (!all)
		return (0);
	info_destroy(all->info, NULL);
	img_destroy_all(all);
	if (all->plr)
		free(all->plr);
	if (all->sprs)
		free(all->sprs);
	if (all->zbuf)
		free(all->zbuf);
	map_destroy(all->map, all->maph);
	win_destroy(all->win);
	free(all);
	return (0);
}
