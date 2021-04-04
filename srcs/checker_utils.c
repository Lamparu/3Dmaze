/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:29:49 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:36:40 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int		check_borders(int x, int y, char **map)
{
	if (y - 1 < 0)
		return (1);
	if ((x - 1 < 0) || (x == ft_strlen(map[y]) - 1))
		return (1);
	if (!map[y + 1] || !map[y - 1])
		return (1);
	if (!map[y][x + 1] || !map[y][x - 1])
		return (1);
	if (ft_strlen(map[y + 1]) <= x || map[y + 1][x] == ' ')
		return (1);
	if (ft_strlen(map[y - 1]) <= x || map[y - 1][x] == ' ')
		return (1);
	return (0);
}

int		valid_point(char x)
{
	if (x == '1' || x == '2' || x == '0' || check_direction(x) || x == ' ')
		return (1);
	return (0);
}

char	*fill_empty_map(char *str, int len, const char *map)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (map[i] == '1')
			str[i] = 'x';
		else if (map[i] == ' ')
			str[i] = ' ';
		else
			str[i] = 'o';
		i++;
	}
	str[len] = '\0';
	return (str);
}

int		check_valid_points(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!valid_point(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		flood_fill(int x, int y, char **map, char **paint)
{
	if (x == 4 && y == 3)
		x = 4;
	if (!map[y] || !map[y][x])
		return (1);
	if (map[y][x] == '1')
		return (1);
	if ((check_borders(x, y, map) && map[y][x] != '1') || map[y][x] == ' ')
		return (0);
	if (paint[y][x] != 'x')
	{
		paint[y][x] = 'x';
		if (flood_fill(x + 1, y, map, paint) == 0)
			return (0);
		if (flood_fill(x - 1, y, map, paint) == 0)
			return (0);
		if (flood_fill(x, y + 1, map, paint) == 0)
			return (0);
		if (flood_fill(x, y - 1, map, paint) == 0)
			return (0);
	}
	return (1);
}
