/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:31:06 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:00 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

t_map	*check_letter(const char *text, t_map *map)
{
	int	i;

	i = check_spaces(0, text);
	if (text[i] == 'R')
		map = get_resolution(map, text + i);
	else if (text[i] == 'W' || text[i] == 'E')
		return (check_we(text, map, i));
	else if (text[i] == 'S' || text[i] == 'N')
		return (check_ns(text, map, i));
	else if (text[i] == 'F' || text[i] == 'C')
		return (check_floor_ceil(text, map, i));
	else if (text[i] == '\n')
		return (map);
	else
		return (info_destroy(map, "UNKNOWN"));
	return (map);
}

t_map	*check_ns(const char *text, t_map *map, int i)
{
	if (text[i] == 'N')
	{
		map->text->no = get_path(text + i + 1, 'O', map->text->no);
		if (!map->text->no)
			return (info_destroy(map, "NO"));
	}
	else if (text[i] == 'S')
	{
		if (ft_isspace(text[i + 1]))
		{
			map->text->sprite = get_path(text + i + 1, ' ',
					map->text->sprite);
			if (!map->text->sprite)
				return (info_destroy(map, "S"));
		}
		else
		{
			map->text->so = get_path(text + i + 1, 'O', map->text->so);
			if (!map->text->so)
				return (info_destroy(map, "S*"));
		}
	}
	return (map);
}

t_map	*check_we(const char *text, t_map *map, int i)
{
	if (text[i] == 'W')
	{
		map->text->we = get_path(text + i + 1, 'E', map->text->we);
		if (!map->text->we)
			return (info_destroy(map, "WE"));
	}
	else if (text[i] == 'E')
	{
		map->text->ea = get_path(text + i + 1, 'A', map->text->ea);
		if (!map->text->ea)
			return (info_destroy(map, "EA"));
	}
	return (map);
}

t_map	*check_floor_ceil(const char *text, t_map *map, int i)
{
	if (text[i] == 'F')
	{
		map->floor = get_colors(map->floor, text + i);
		if (!map->floor)
			return (info_destroy(map, NULL));
	}
	else if (text[i] == 'C')
	{
		map->ceil = get_colors(map->ceil, text + i);
		if (!map->ceil)
			return (info_destroy(map, NULL));
	}
	return (map);
}

int	check_resolution(int x, int y)
{
	if (x < 1 || y < 1)
	{
		printf("Error\nResolution error");
		return (0);
	}
	return (1);
}
