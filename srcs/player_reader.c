/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:31:24 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:06 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int	check_direction(char a)
{
	if (a == 'N' || a == 'S' || a == 'E' || a == 'W')
		return (1);
	return (0);
}

t_all	*get_direction(char a, t_all *all)
{
	double	norm;

	if (a == 'N')
		all->plr->dir.y = -1.0;
	else if (a == 'S')
		all->plr->dir.y = 1.0;
	else if (a == 'W')
		all->plr->dir.x = -1.0;
	else if (a == 'E')
		all->plr->dir.x = 1.0;
	all->plane = vec_rotate(all->plr->dir, M_PI_2);
	norm = hypot(all->plane.x, all->plane.y);
	all->plane.x = all->plane.x / norm * 0.66;
	all->plane.y = all->plane.y / norm * 0.66;
	return (all);
}

t_all	*get_plr(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (check_direction(all->map[i][j]))
			{
				if (all->plr->pos.x == -1 || all->plr->pos.y == -1)
				{
					all->plr->pos.x = j + 0.5;
					all->plr->pos.y = i + 0.5;
					all = get_direction(all->map[i][j], all);
				}
				else
					exit_err(all, "Two players", 2);
			}
			else if (all->map[i][j] == '2')
				all->snum++;
		}
	}
	return (all);
}
