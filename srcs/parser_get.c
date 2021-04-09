/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcierra <lcierra@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:31:14 by lcierra           #+#    #+#             */
/*   Updated: 2021/04/04 21:40:03 by lcierra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/cub.h"

t_map	*get_resolution(t_map *map, const char *text)
{
	size_t	i;

	i = 1;
	map->r_x = 0;
	map->r_y = 0;
	if (!text[i] || text[i] != ' ')
		return (map);
	i = check_spaces(i, text);
	i = get_num(i, text, &map->r_x);
	i = check_spaces(i, text);
	i = get_num(i, text, &map->r_y);
	i = check_spaces(i, text);
	if (text[i] != '\n')
	{
		printf("Error\nResolution error");
		info_destroy(map, NULL);
		map = NULL;
	}
	return (map);
}

t_all	*get_sprites(t_all *all)
{
	int	i;
	int	j;
	int	n;

	if (all->snum == 0)
		return (all);
	all->sprs = malloc(sizeof(t_sprite) * all->snum);
	if (!all->sprs)
		exit_err(all, "Malloc", 1);
	i = -1;
	n = 0;
	while (all->map[++i] && n < all->snum)
	{
		j = -1;
		while (all->map[i][++j] && (n < all->snum))
		{
			if (all->map[i][j] == '2')
			{
				all->sprs[n].pos.y = i;
				all->sprs[n].pos.x = j;
				n++;
			}
		}
	}
	return (all);
}

char	*get_path(const char *text, char next, char *path)
{
	size_t	i;
	size_t	j;
	int		len;

	j = 0;
	if (!(path_err(text, path, next)))
		return (NULL);
	i = check_spaces(1, text);
	if (text[i] == '.' || text[i] == '/')
	{
		len = get_len(text + i);
		if (len < 6)
			return (NULL);
		path = malloc(sizeof(char) * (len + 1));
		if (!path)
			return (NULL);
		while (text[i] != '\n' && text[i] != ' ' && text[i] != '\t')
		{
			path[j] = text[i];
			i++;
			j++;
		}
		path[j] = '\0';
	}
	return (path);
}

t_color	*get_colors(t_color *st, const char *str)
{
	int	i;

	i = 1;
	if (st->red >= 0 || st->blue >= 0 || st->green >= 0)
	{
		printf("Error\nColor error");
		free(st);
		return (NULL);
	}
	if (!str[i] || str[i] != ' ')
		return (st);
	i = check_color(str, i, &st->red, 'R');
	if (i < 0)
		return (st);
	i = check_color(str, i, &st->green, 'G');
	if (i < 0)
		return (st);
	i = check_color(str, i, &st->blue, 'B');
	if (str[i] && str[i] != '\n')
	{
		printf("Error\nColor error");
		free(st);
		st = NULL;
	}
	return (st);
}

t_all	*get_map_wh(t_all *all)
{
	int	y;
	int	x;
	int	max;

	y = 0;
	max = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
			x++;
		if (max < x)
			max = x;
		y++;
	}
	all->maph = y;
	return (all);
}
