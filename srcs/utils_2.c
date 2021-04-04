/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:32:09 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:17 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

t_vec	vec_rotate(t_vec vec, double angle)
{
	t_vec v;

	v.x = vec.x * cos(angle) - vec.y * sin(angle);
	v.y = vec.x * sin(angle) + vec.y * cos(angle);
	return (v);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i])
	{
		if (s2[i])
		{
			if (s2[i] != s1[i])
				return (0);
		}
		i++;
	}
	if (s2[i])
		return (0);
	return (1);
}

t_all	*chose_resolution(t_all *all)
{
	int x;
	int y;

	mlx_get_screen_size(all->win->mlx, &x, &y);
	if (x < all->info->r_x || y < all->info->r_y)
	{
		all->info->r_x = x;
		all->info->r_y = y;
	}
	return (all);
}

int		ft_isspace(char a)
{
	if (!a)
		return (0);
	if (a == ' ')
		return (1);
	return (0);
}

int		ft_isdigit(char a)
{
	if (!a)
		return (0);
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}
