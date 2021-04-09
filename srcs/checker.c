/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:29:59 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:36:58 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

char	**copy_map(char **map, int h)
{
	char	**new;
	int		y;
	int		len;

	new = malloc(sizeof(char *) * (h + 1));
	if (!new)
	{
		printf("Error\nMalloc map error");
		return (NULL);
	}
	y = 0;
	while (y < h)
	{
		len = ft_strlen(map[y]);
		new[y] = malloc(sizeof(char) * (len + 1));
		if (!new[y])
			return (ft_split_error(new, y, "Malloc"));
		new[y] = fill_empty_map(new[y], len, map[y]);
		y++;
	}
	new[y] = NULL;
	return (new);
}

int	check_cub(char *fn)
{
	int	len;

	len = ft_strlen(fn);
	if (len < 5)
		return (0);
	return (ft_strcmp(fn + len - 4, ".cub"));
}

int	check_map(t_all *all)
{
	int		x;
	int		y;
	char	**map;

	if (!all->map)
		return (0);
	if (!check_valid_points(all->map))
		return (0);
	map = copy_map(all->map, all->maph);
	if (!map)
		return (0);
	y = 0;
	while (y < all->maph)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'o' && !flood_fill(x, y, all->map, map))
				return (0);
			x++;
		}
		y++;
	}
	map_destroy(map, all->maph);
	return (1);
}

int	check_player(t_all *all)
{
	if (!all->plr)
		return (0);
	if (all->plr->pos.x < 1 || all->plr->pos.y < 1)
		return (0);
	return (1);
}

void	checker(t_all *all)
{
	if (check_player(all) == 0)
		exit_err(all, "Player content", 4);
	if (check_map(all) == 0)
		exit_err(all, "Map content", 4);
}
