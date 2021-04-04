/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:31:09 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:01 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

int		check_map_begin(const char *str)
{
	size_t	i;

	i = check_spaces(0, str);
	if (ft_isdigit(str[i]))
		return (1);
	return (0);
}

int		check_texture(t_texture *tex)
{
	if (!tex->we || !tex->ea || !tex->so || !tex->no || !tex->sprite)
	{
		printf("Error\nTexture paths error");
		return (0);
	}
	if (!check_open_tex(tex->no, "NO"))
		return (0);
	if (!check_open_tex(tex->so, "SO"))
		return (0);
	if (!check_open_tex(tex->ea, "EA"))
		return (0);
	if (!check_open_tex(tex->we, "WE"))
		return (0);
	if (!check_open_tex(tex->sprite, "SPRITE"))
		return (0);
	return (1);
}

int		check_colors(t_color *col, char *side)
{
	if (col->green < 0 && col->red < 0 && col->blue < 0)
	{
		printf("Error\nNo info for %s color", side);
		return (0);
	}
	if (col->green < 0 || col->green > 255)
	{
		printf("Error\nGreen color in %s error", side);
		return (0);
	}
	if (col->blue < 0 || col->blue > 255)
	{
		printf("Error\nBlue color in %s error", side);
		return (0);
	}
	if (col->red < 0 || col->red > 255)
	{
		printf("Error\nRed color in %s error", side);
		return (0);
	}
	return (1);
}

int		check_map_info(t_map *map)
{
	if (!check_resolution(map->r_x, map->r_y))
		return (0);
	if (!check_texture(map->text))
		return (0);
	if (!check_colors(map->floor, "floor"))
		return (0);
	if (!check_colors(map->ceil, "ceil"))
		return (0);
	return (1);
}

int		path_err(const char *text, char *path, char next)
{
	if (path)
	{
		free(path);
		return (0);
	}
	if ((text[0] != next) || (next != ' ' && text[1] != ' '))
		return (0);
	return (1);
}
